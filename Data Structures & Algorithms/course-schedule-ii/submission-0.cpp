class Solution {
public:
    struct Node{
        int val;
        int in_degree;
        unordered_set<int> children;
        Node(int v) : val(v){
            in_degree = 0;
            children = {};
        }
    };
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, Node*> all_nodes;
        for(unsigned int i = 0; i < numCourses; i++){
            all_nodes[i] = new Node(i);
        }
        for(vector<int> courses : prerequisites){
            all_nodes[courses[1]]->children.insert(courses[0]);
            all_nodes[courses[0]]->in_degree++;
        }
        queue<Node*> topo_queue;
        for(const auto& [course, node] : all_nodes){
            if(node->in_degree == 0){
                topo_queue.push(node);
            }
        }
        vector<int> course_order;
        while(!topo_queue.empty()){
            Node* node = topo_queue.front();
            topo_queue.pop();
            course_order.push_back(node->val);
            for(const auto& child_course : node->children){
                if(--all_nodes[child_course]->in_degree == 0){
                    topo_queue.push(all_nodes[child_course]);
                }
            }
        }
        for(unsigned int i = 0; i < numCourses; i++){
            if(all_nodes[i]->in_degree != 0){return {};}
        }
        return course_order;
    }
};
