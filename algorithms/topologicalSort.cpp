

/*
Example of topological sort with bfs to explore a DAG.  
*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegrees(numCourses,0);
    vector<vector<int>> graph(numCourses);
    for (vector<int>& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]);
        indegrees[pre[0]]++;
    }
    vector<int> order;
    queue<int> q;
    for (int i = 0;i<numCourses;i++) {
        if (indegrees[i]==0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        for (auto& nei : graph[course]) {
            if (--indegrees[nei]==0) {
                q.push(nei);
            }
        }
    }
    return order.size()==numCourses ? order : vector<int>();
}