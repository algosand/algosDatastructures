int findPosIdentifierVersion(string &str, char delim = ' ') {
    int pos = str.find(delim);
    return pos;
}

// A box object that contains the identifier and version. 
struct Box {
    string id, version;
    void init(string& identifier, string& ver) {
        id = identifier;
        version = ver;
    }
};
vector<string> sortBoxes(vector<string> boxList) {
    vector<Box> old, nnew;
    for (string &box : boxList) {
        int pos = findPosIdentifierVersion(box);
        Box bo;
        string identifier = box.substr(0,pos), ver = box.substr(pos+1);
        bo.init(identifier, ver);
        // if alphabet character in the version it is old generation
        if (isalpha(bo.version[0])) {
            old.push_back(bo); 
        } else {
            nnew.push_back(bo);
        }
    }
    sort(old.begin(),old.end(), [](const auto& boxA, const auto& boxB) {
        if (boxA.version!=boxB.version) {
            return boxA.version<boxB.version;
        }
        return boxA.id < boxB.id;
    });
    vector<string> sortedBoxes;
    for (auto& box : old) {
        sortedBoxes.push_back(box.id + ' ' + box.version);
    }
    for (auto& box : nnew) {
        sortedBoxes.push_back(box.id + ' ' + box.version);
    }
    return sortedBoxes;
}