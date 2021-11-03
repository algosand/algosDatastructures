#include <bits/stdc++.h>
using namespace std;
/*
polynomial rolling hash or rabin-karp algorithm.  
Used hashing to do O(1) comparisons between pattern and text. 
string matching algorithm
In general will need to compute the window size of the pat and generate hash for
all the substrings in the string to find if pat is in the text. 
*/
int mod = 1e9 + 7;
int getHash(const string& s, vector<long long>& pows) {
    int mod = 1e9 + 7, hashed = 0;
    long long p = 31;
    // O(m)
    for (int i = 0;i < s.size();i++) {
        hashed = (hashed + ((s[i]-'a'+1)*pows[i])%mod)%mod;
    }
    return hashed;
}

// General idea of rabinkarp with rolling hash
// polynomial equation c0*p^0+c1*p^1+c2*p^2+...ck-1*p^k-1, where k is length of max(n,m)
/*
You can find the number of times a pattern matches a string in O(n+m) TC
*/
vector<int> rabinKarp(const string& s, const string& pat) {
    int n = s.size(), m = pat.size();
    int p = 31;
    // precompute the powers
    vector<long long> pows(max(n,m),0);
    pows[0] = 1;
    for (int i = 1;i < pows.size();i++) {
        pows[i] = (pows[i-1]*p)%mod;
    }
    // precompute the hashes for the string
    /*
    hashes = [c0p^0, c0p^0+c1p^1, c0p^0+c1p^1+c2p^2, ...]
    */
    vector<int> hashes(n+1, 0);
    for (int i = 0;i < n;i++) {
        hashes[i+1] = (hashes[i] + ((s[i]-'a'+1)*pows[i]))%mod;
    }
    // compute the pattern hash
    int patHash = getHash(pat, pows);
    vector<int> matches;
    // find the occurrences
    for (int i = 0;i < n - m + 1;i++) {
        int curHash = (hashes[i+n]-hashes[i] + mod)%mod; // because of modding it is not guaranteed that hashes[i+n]>hashes[i] => thus you need to mod this result
        if (curHash == (patHash*pows[i])%mod) {
            matches.push_back(i);
        }
    }
    return matches;
}
/*
A variant of rolling hash that is useful for binary searching and using rolling hash. such as find common substring amongst multiple strings
The main difference is how you are computing the rolling hash, I don't precompute it because we can't
just easily update the curHash and multiply it by the pows[i] to see if it equals. 
We need to store rolling hashes at each iteration of binary search, with varying lengths, best way
is to use this formula for updating curHash = (a0p^2+a1p^1+a2p^0 - a0p^2)*p+a4p^0
Basically we are adding the next term, and remove the earliest term which has the maximum power we know 
for the length of the characters.  and we need multiply by p to update it for the next polynomial hash. 
This way you can store all polynomial hashes for some substring length, 
Then I can iterate through all substring polynomial hashes of the next substring and see if it was already seen
in an efficient manner.  
*/

auto check = [&](const int len) {
    // Precompute the hashes
    unordered_set<int> seen;
    int curHash = 0;
    for (int i = 0;i < n;i++) {
        curHash = i<len ? (curHash + ((nums1[i]+1)*pows[len-i-1])%mod)%mod : (((curHash-((nums1[i-len]+1)*pows[len-1])%mod+mod)%mod)*pows[1])%mod + nums1[i]+1;
        if (i>=len-1) {
            seen.insert(curHash);
        }
    }
    curHash = 0;
    for (int i = 0;i < m;i++) {
        curHash = i<len ? (curHash + ((nums2[i]+1)*pows[len-i-1])%mod)%mod : (((curHash-((nums2[i-len]+1)*pows[len-1])%mod+mod)%mod)*pows[1])%mod + nums2[i]+1;
        if (i>=len-1 && seen.count(curHash)>0) {
            return true;
        }
    }
    return false;
};


/*
Couple of ways to generate the polynomial hash equations
hashes = [c0p^0, c0p^0+c1p^1, c0p^0+c1p^1+c2p^2, ...]

if you take hashes[lhs]-hashes[rhs] = c1p^1+c2p^2 = hashes[3]-hashes[1], 
so to check if a string matches with that you need to make sure to multiple
any pattern hash by pows[1], cause if it only has two terms it may be 
c1p^0+c2p^1, which is equal but need to multiple by p. 
*/
vector<int> hashes(n+1, 0);
for (int i = 0;i < n;i++) {
    hashes[i+1] = (hashes[i] + ((s[i]-'a'+1)*pows[i]))%mod;
}

/*
hashes = [c0p^0, c0p^1+c1p^0, c0p^2+c1p^1+c2p^0,...]

If you take hashes[lhs]-hashes[rhs]*pows[rhs-lhs] = hashes[3]-hashes[1]*pows[3-1]=c0p^2+c1p^1+c2p^0 - c0p^2 = c1p^1+c2p^0
Which is the polynomial hash for that string, you can now compare this to another string to see if it matches
*/
vector<int> hashes(n+1,0);
for (int i=0;i<n;i++) {
    hashes[i+1]=(hashes[i]*pows[i]+(s[i]-'a'+1))%mod;
}
/*
a0p^0+a1p^1+a2p^2 for len=3 prefix
a0p^2 + a1p^1+a2^p2, which if it is aba and aba it works.  

These are two opposite ways to generate a polynomial hash function

one is to multiple all the previous by p
or to add on and multiple by higher powers of p. 
*/

/*
Polynomial hash for integers, let's say you have a series of integers that can be between the value of -1e5 to 1e5, that means 
you have 200,000 unique integers you need to hash, so I choose p = 200,003, the next prime number,
and I want to check that I have three unique integers via a polynomial hash.  
*/

const int MOD = 1e9+7;
const long long p = 2e5+3, offset = 1e5;
int getHash(long long x, long long y, long long z) {
    x+=offset;
    y+=offset;
    z+=offset;
    return ((x*p)%MOD + ((y*p)%MOD*p)%MOD + (((z*p)%MOD*p)%MOD*p)%MOD)%MOD;
}

/*
This is a rolling hash solution to a problem of finding the longest duplicate substring.  It is a very good example of using a rolling hash
algorithm. 

A variant of rolling hash that is useful for binary searching and using rolling hash. such as find common substring amongst multiple strings
The main difference is how you are computing the rolling hash, I don't precompute it because we can't
just easily update the curHash and multiply it by the pows[i] to see if it equals. 
We need to store rolling hashes at each iteration of binary search, with varying lengths, best way
is to use this formula for updating curHash = (a0p^2+a1p^1+a2p^0 - a0p^2)*p+a4p^0

Additional thoughts that are important is that there is a lot of substring combinations to try here.
There are 2^n, so with this there is a higher chance of collision with the rolling hash.  The reason behind this collision is because
there are two things you can say about a hash.  Suppose the hash = 22, now if this hash does exist in the map of seen hashes previously.  
That indicates that this string does not exist, has not been processed prior.  That means it is not a duplicate.  
Alternatively if the hash = 22 does exist in the map, that means the string could be a duplicate.  So to actually determine if it is a 
duplicate you need to iterate through all previous strings that produce a duplicate by storing the starting index. and find if it actually is
a duplicate.  

But this algorithm is still almost (maybe that is amortized) O(nlogn), because the hash is good, there isn't going to be too many collisions.  With a poor hash it would be worse case O(n^2logn)
*/
const long long p = 31;
const int MOD = 1e9+7;
string longestDupSubstring(string s) {
    int n = s.size();
    int lo = 0, hi = n-1;
    auto check = [&](const int len) {
        string res = "";
        if (len==0) {return res;}
        unordered_map<int, vector<int>> seen;
        int hash = 0;
        vector<long long> pows(len,1);
        for (int i = 1;i<len;i++) {
            pows[i] = (pows[i-1]*p)%MOD;
        }
        for (int i = 0;i<len;i++) {
            int coeff = s[i]-'a';
            hash = ((hash*p)%MOD+coeff)%MOD;
        }
        seen[hash].push_back(0);
        for (int i = len;i<n;i++) {
            int aprev = s[i-len]-'a', acur = s[i]-'a';
            hash = (hash - (aprev*pows.end()[-1])%MOD + MOD)%MOD;
            hash = ((hash*p)%MOD + acur)%MOD;
            if (seen.find(hash)!=seen.end()) {
                string cand = s.substr(i-len+1,len);
                for (auto &start : seen[hash]) {
                    if (strcmp(s.substr(start,len).data(), cand.data())==0) {
                        return cand;
                    }
                }
            }
            seen[hash].push_back(i-len+1);
        }
        return res;
    };
    while (lo<hi) {
        int mid = lo+hi+1>>1;
        string tmp = check(mid);
        if (!tmp.empty()) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return check(lo);
}

 long long solve(int X,int Y,string S){
      long long res = 0;
      int cp = 0, cr = 0;
      for (int i = 0;i<S.size();i++) {
          char ch = S[i];
          if (cp>0 && ch=='r' && X>=Y) {
              res += X;
              cp--;
              cr--;
          } else if (cr>0 && ch=='p' && X<=Y) {
              res += Y;
              cr--;
              cp--;
          } else if (ch!='p' && ch!='r' && cp>0 && cr>0) {
              int cnt = min(cp,cr);
              res += (cnt*(Y<X ? Y : X));
              cp=0;
              cr=0;
          }
          cp += (ch=='p');
          cr += (ch=='r');
      }
      int cnt = min(cp,cr);
      if (cp>0 && cr>0) {
          res += (cnt*(Y<X ? Y : X));
      }
      return res;
    }

/*
[-83761158,187114762,816000962,-949756892,-274929249,-459070835,-36632426,-489579889,979826818,-375820333,-39829274,942134974,-916648780,-672373100,-572331310,-89079409,347815191,149534018,433054586,590212945,4826754,-660421633,-408655396,220586631,729650559,-749848828,347297251,98676269,97525608,-539034149,-297795554,486100907,146095071,-715187392,754310585,-325345857,-249831646,45727812,159805720,-171361738,-616916169,-654274181,905886119,-571931511,887486033,205709839,524760185,-781302910,-692869250,96634884,-153193875,412717225,34981529,-141067973,53245241,-300238631,-705009162,-474280838,-410345942,-680840053,757809145,-688905564,796975964,435569661,340954586,162284349,791966616,-903231966,433240210,-291702604,-494796766,711144493,-21728204,-212368037,-871096294,47348832,55813367,-169032442,-139076403,-897459937,-950500519,-170626743,118210313,597907479,165281814,-921726525,947220449,606271474,-152881804,-482050103,186156052,-909898088,-741307082,-40477594,632263291,306844958,-42863916,823552961,911323344,-237280507,-537546628,4402114,492691760,-787825961,1785730,636125421,-181551024,496934922,907206220,-45384519,892505492,-517891236,-472542046,457490815,241833827,385354416,-901047814,549517597,730373559,-275361901,-811596386,531013335,-957555770,-958497298,-322321335,90405657,476443008,556445221,165702324,90985734,361009680,105488252,904848589,-262498267,-41437923,489477630,984707702,-347218524,-710766392,-478467463,-344900508,-957051669,-82093384,510268268,-963740797,821643172,-300418877,-985292461,607707797,-304753205,113880999,-683032822,-762891935,353834085,-422928541,-734075281,-948768345,-967005747,-919049501,-792663717,-613322797,-936176953,642527373,327889962,-67671801,-95084849,-415857420,-311359999,-21287507,-706281454,-87063390,-539970055,345041113,998191592,586286149,-89282641,-168209055,856434439,432504667,813756907,618044549,591588256,303568877,393320949,222176805,-82656629,305315646,-224220784,-840873200,-24398666,-653039817,283041975,-457138269,274813864,-959674420,393455208,-64758952,-86839066,745682987,979753945,559795628,626244320,252587329,-752871565,-663183068,-565694401,352480237,892099298,-236621586,-3649203,-597301482,-767552443,275885519,646955362,-128499933,-414751220,-445892242,-734996209,-332382212,-29413357,833117767,288731564,-409453123,-540661260,-445809349,-399693753,-866223560,98199947,812569205,886613409,956820974,649267139,272087990,72506966,-112782579,-700059085,594901384,311870365,837777783,-415534896,180457475,13044901,-220161518,723066575,369431098,-883966441,-14332487,-914467383,-333600760,738078488,295425420,-837791222,337985832,-962312208,329068509,703875061,-951065718,-78970192,106510494,579589136,887907071,-117708992,585722775,944953914,-172706897,-233980650,299746461,972569472,893867834,794186726,166943524,-623597378,-306479784,-216994220,-724380421,-414301818,-966990949,-482621551,522314092,-985918514,-28169539,-54070193,509883395,-513397546,779231066,-739185627,-833908688,525582112,-278314694,903370067,-731443089,584811018,-985963753,-424810844,-979869771,-301918326,264659301,440490172,-98374801,-419312904,72622850,-960404399,830169796,837481503,75954741,-36969656,398523570,5520345,402604268,-737406285,894883546,-40268207,-9097400,307929305,657324611,-906438655,-67414677,-857979182,716544204,691702022,-771040165,-530532279,-549340359,-309146296,725121885,-199848000,-713894853,-957293910,-889002253,457225968,376753583,-978171050,-731744114,529325853,835729528,-984467724,261592051,703055835,-852682550,-895444580,-958035980,79182225,-412911822,-273412032,422900107,-265097809,676883819,888012485,-891540134,413661772,519681893,-28787069,508536740,-572545622,672752776,-870747806,-982393653,-84593299,-142893148,740331241,-353632927,-380068629,772431143,954679842,-774209623,79279976,-709077919,258163522,746724392,18798734,403953858,-844533083,-272401614,162877594,243129243,757473949,111109038,-451925406,869014588,595317328,-666711511,870882083,121867627,515522338,815281240,180275909,978975861,-330246033,795556656,263656645,707498033,368075248,328611588,-981826212,-125185785,673060042,477171807,-603381855,170729742,316931075,-937755438,-102590976,-271735591,742305218,-713317348,248574958,-548608815,682871338,-709310542,134844539,-317071460,-846958331,888216965,881730693,-333887417,-182914391,-392033212,-66075702,290460041,561269694,-695744610,-746992952,-606181441,-548223579,-131386799,-499500736,-284341884,851975990,590765010,885162890,820169000,635123350,510638649,-25507347,-223547407,-624857363,-845925390,-568922317,-877411412,315719179,89304645,-693158426,-910673203,884270865,-820884468,319816672,-225674489,-146221013,262520617,-214296696,290403573,-197718196,960840836,-827508778,-211712260,-456645031,745274328,61488304,-706344647,179613112,594413720,-906276386,-544232755,792427074,-135906974,-212657424,-736690083,-709161708,-427589443,-414677690,411139808,-814516246,-831293244,-880487262,-431504218,533183802,563151853,120479634,627050053,644402188,-186625218,-172027805,-231040208,-280440258,356538018,207715179,856304737,181720612,-485825198,-153218029,421355745,582881142,409862893,-340280625,345699195,-870375922,-418321530,-390140391,172138386,787796886,282349877,-720916879,-618624472,439657003,-344292096,-947128588,-101216547,-970014484,764637456,-606245461,-99515209,611012705,368054653,-208841498,241090224,-326777454,-370138524,-778967818,940397490,-558584855,-462247599,-856525703,675393492,-60135254,679371819,-54689074,736491134,449528011,926065816,285199658,-558943841,954309638,332679223,-495401910,-864803502,-244511295,333689401,343406845,818046074,852163603,658803116,-28021270,-4182362,440819126,-986865173,707995482,672196498,333736088,842952486,-450067591,682296485,238195830,-152270944,-928893014,472343663,-686417848,991073036,-115828606,783220953,-333065213,-178629771,284711222,-859326130,-380217177,-188666595,204269423,-584144173,-916368690,194384032,-441987396,85531014,-911551664,371950436,497691185,-289105228,-321969151,-483460577,-762639590,-123336500,947478190,-67871687,421193894,-185590344,-379910695,-388962856,-669115258,-87699318,-239329587,780772080,409004294,-192331884,-917977037,-368326946,-790193444,173179291,554566630,-572063508,239891859,473588932,-988769955,328454826,-306659418,158811685,-392966072,-334964144,-795295331,244357872,-132570550,413195910,-284119532,301774691,-948669158,-394744747,380484717,141391761,-824370603,-521887157,203637991,-420301400,155423132,676179153,-966685544,488303729,-501436975,-135628246,393569003,-670800284,1]
389
838
*/