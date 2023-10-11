#include "arithmeticExpression.h"

/* PUBLIC FUNCTIONS */

arithmeticExpression::arithmeticExpression(const string &infixExpression) {
    this->infixExpression = infixExpression;
    root = nullptr;
}

arithmeticExpression::~arithmeticExpression() {
    DestroyRecursive(root);
}

// BSTree destructor from https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
void arithmeticExpression::DestroyRecursive(TreeNode *node) {
    if (node) {
        DestroyRecursive(node->left);
        DestroyRecursive(node->right);
        delete node;
    }
}

void arithmeticExpression::buildTree() {
    string postfixExpression = infix_to_postfix();
    stack<TreeNode*> expression;
    char letter = 'a';
    char c;
    for (unsigned i = 0; i < postfixExpression.size(); ++i) {
        c = postfixExpression.at(i);
        if (c == '+' or c == '-' or c == '*' or c == '/') {
            TreeNode* rootNode = new TreeNode(c, letter + i);
            rootNode->left = expression.top();
            expression.pop();
            rootNode->right = expression.top();
            expression.pop();
            expression.push(rootNode);
        }

        else {
            expression.push(new TreeNode(c, letter +i));
        }
    }

    root = expression.top();
    expression.pop();
}

void arithmeticExpression::infix() {
    infix(root);
}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::postfix() {
    postfix(root);
}

// void arithmeticExpression::visualizeTree(const string &outputFilename){
//     ofstream outFS(outputFilename.c_str());
//     if(!outFS.is_open()){
//         cout<<"Error opening "<< outputFilename<<endl;
//         return;
//     }
//     outFS<<"digraph G {"<<endl;
//     visualizeTree(outFS,root);
//     outFS<<"}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
// }

/* PRIVATE FUNCTIONS */

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode *node) {
    if (node != nullptr) {
        if (node->left != nullptr || node->right != nullptr) {
            cout << "(";
        }

        infix(node->right);
        cout << node->data;
        infix(node->left);

        if (node->left != nullptr or node->right != nullptr) {
            cout << ")";
        }
    }
    else {
        /* nothing */
    }
}

void arithmeticExpression::prefix(TreeNode *node) {
    if (node != nullptr) {
        cout << node->data;
        prefix(node->right);
        prefix(node->left);
    }
    else {
        /* nothing */
    }
}

void arithmeticExpression::postfix(TreeNode *node) {
    if (node != nullptr) {
        postfix(node->right);
        postfix(node->left);
        cout << node->data;
    }
    else {
        /* nothing */
    }
}