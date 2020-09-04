#include <string>
#include <vector>
#include <queue>

using namespace std;
// 우선 순위 큐에 넣을 노드
struct qnode {
    int x, y, num; // 좌표, 노드번호
};

// 우선 순위 비교 구조체
struct compare {
    bool operator()(qnode& a, qnode& b) {
        // y좌표가 똑같다면
        if (a.y == b.y) {
            return a.x > b.x; // x좌표 오름차순
        }
        // y좌표 내림차순
        return a.y < b.y;
    }
};

// 트리 노드 구조체
struct TreeNode {
    int num, x;
    TreeNode* left, * right;
};

// 기존 트리 tree에 현재 노드 curNode를 삽입
void insert(TreeNode* tree, TreeNode* curNode) {
    // 왼쪽 노드가 비어있고 x좌표 값이 작을 때
    if (tree->left == NULL && tree->x > curNode->x) {
        tree->left = curNode; // 왼쪽 노드에 현재 노드 삽입
    }
    // 왼쪽 노드가 비어있지 않고 x좌표 값이 작을 때
    else if (tree->left != NULL && tree->x > curNode->x) {
        insert(tree->left, curNode); // 왼쪽 노드로 이동
    }
    // 오른쪽 노드가 비어있고 x좌표 값이 클 때
    else if (tree->right == NULL && tree->x < curNode->x) {
        tree->right = curNode; // 오른쪽 노드에 현재 노드 삽입
    }
    // 오른쪽 노드가 비어있지 않고 y좌표 값이 클 때
    else if (tree->right != NULL && tree->x < curNode->x) {
        insert(tree->right, curNode);
    }
}

vector<vector<int>> answer;

// 전위 순회
void preorder(TreeNode* tree) {
    if (tree == NULL) return;
    answer[0].push_back(tree->num);
    preorder(tree->left);
    preorder(tree->right);
}

// 후위 순회
void postorder(TreeNode* tree) {
    if (tree == NULL) return;
    postorder(tree->left);
    postorder(tree->right);
    answer[1].push_back(tree->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    answer.resize(2); // 전위순회, 후위순회 결과 저장 공간 만들기
    // 1. 우선 순위 큐에 노드 넣기
    priority_queue<qnode, vector<qnode>, compare> pq;
    for (int i = 0; i < nodeinfo.size(); i++) {
        qnode qn;
        qn.x = nodeinfo[i][0];
        qn.y = nodeinfo[i][1];
        qn.num = i + 1;
        pq.push(qn);
    }
    // 2. 트리 생성
    // 트리 루트 생성
    TreeNode* tree = new TreeNode();
    qnode topNode = pq.top();
    tree->num = topNode.num;
    tree->x = topNode.x;
    pq.pop();
    // 트리에 노드 순서대로 삽입
    while (!pq.empty()) {
        topNode = pq.top();
        pq.pop();
        TreeNode* curNode = new TreeNode();
        curNode->num = topNode.num;
        curNode->x = topNode.x;
        insert(tree, curNode);
    }
    // 3. 전위 순회, 후위 순회
    preorder(tree);
    postorder(tree);
    return answer;
}