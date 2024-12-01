#include <iostream>

using namespace std;
class AvlNode
{
public:
    string data;
    AvlNode *left;
    AvlNode *right;
    AvlNode(string x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class StackAvlNode
{
public:
    AvlNode *address;
    StackAvlNode *next;
    StackAvlNode(AvlNode *x)
    {
        address = x;
        next = NULL;
    }
};
class Stack
{
public:
    StackAvlNode *top = NULL;
    void push(AvlNode *x)
    {
        StackAvlNode *n = new StackAvlNode(x);
        if (top == NULL)
        {
            top = n;
        }
        else
        {

            n->next = top;
            top = n;
        }
    }
    AvlNode *pop()
    {
        StackAvlNode *temp = top;
        top = top->next;
        return temp->address;
    }
};
class Queue
{
public:
    StackAvlNode *front = NULL;
    StackAvlNode *rear = NULL;
    void enqueue(AvlNode *x)
    {
        StackAvlNode *n = new StackAvlNode(x);
        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
    AvlNode *dequeue()
    {
        AvlNode *temp = front->address;
        front = front->next;
        return temp;
    }
};
class AVL

{
public:
    AvlNode *root = NULL;
    int maxl = 0;
    int ll = 0, rr = 0, lr = 0, rl = 0;
    AvlNode *ggparent, *grandparent, *parent, *child;
    int height(AvlNode *n)
    {
        if (n == NULL)
            return 0;
        Queue q;
        int c = 1, k = 0, level = 0;
        q.enqueue(n);
        while (c > 0)
        {
            if (q.front != NULL)
            {
                AvlNode *temp = q.dequeue();
                if (temp->left != NULL)
                {
                    q.enqueue(temp->left);
                    k++;
                }
                if (temp->right != NULL)
                {
                    q.enqueue(temp->right);
                    k++;
                }
            }
            c--;
            if (c == 0)
            {
                c = k;
                k = 0;
                level++;
            }
        }

        return level;
    }
    AvlNode *findParent(AvlNode *t)
    {
        AvlNode *temp = root;
        AvlNode *prev = root;
        while (1)
        {
            if (temp == t)
            {
                return prev;
                break;
            }
            else if (temp->data.compare(t->data) > 0)
            {
                prev = temp;
                temp = temp->left;
            }
            else if (temp->data.compare(t->data) < 0)
            {
                prev = temp;
                temp = temp->right;
            }
        }
    }
    void llRotate()
    {
        if (root == grandparent)
        {
            AvlNode *temp = parent->right;
            parent->right = grandparent;
            grandparent->left = temp;
            root = parent;
        }
        else
        {
            ggparent = findParent(grandparent);

            AvlNode *temp = parent->right;
            parent->right = grandparent;
            grandparent->left = temp;
            if (ggparent->data.compare(parent->data) >

                0)

                ggparent->left = parent;
            else
                ggparent->right = parent;
        }
        cout << "llRotate" << endl;
        ll = 0, rl = 0, lr = 0, rr = 0;
    }
    void lrRotate()
    {
        AvlNode *temp = child->left;
        child->left = parent;
        parent->right = temp;
        grandparent->left = child;
        temp = parent;
        parent = child;
        child = temp;
        llRotate();
        cout << "lrRotate" << endl;
    }
    void rlRotate()
    {
        AvlNode *temp = child->right;
        child->right = parent;
        parent->left = temp;
        grandparent->right = child;
        temp = parent;
        parent = child;
        child = temp;
        cout << "rlRotate" << endl;
        rrRotate();
    }
    void rrRotate()

    {
        if (root == grandparent)
        {
            AvlNode *temp = parent->left;
            parent->left = grandparent;
            grandparent->right = temp;
            root = parent;
            cout << "rrRotate" << endl;
        }
        else
        {
            ggparent = findParent(grandparent);
            AvlNode *temp = parent->left;
            parent->left = grandparent;
            grandparent->right = temp;
            if (ggparent->left == grandparent)
                ggparent->left = parent;
            else
                ggparent->right = parent;
            cout << "rrRotate" << endl;
        }
        ll = 0, rl = 0, lr = 0, rr = 0;
    }
    void balance()
    {
        Stack s;
        AvlNode *temp = root;
        s.push(root);
        while (s.top != NULL)
        {
            while (temp != NULL)
            {
                temp = temp->left;
                if (temp != NULL)
                    s.push(temp);
            }
            temp = s.pop();

            int l = height(temp->left);
            int ri = height(temp->right);
            int bf = l - ri;
            if (!(bf == 0 || bf == -1 || bf == 1))
            {
                if (ll == 1)
                    llRotate();
                else if (rr == 1)
                    rrRotate();
                else if (lr == 1)
                    lrRotate();
                else if (rl == 1)
                    rlRotate();
            }
            if (temp->right != NULL)
                s.push(temp->right);
            temp = temp->right;
        }
    }
    void insert(string x)
    {
        int l = 0, r = 0;
        if (root == NULL)
            root = new AvlNode(x);
        else
        {
            AvlNode *n = new AvlNode(x);
            AvlNode *temp = root;
            while (1)
            {
                if (temp->data.compare(x) > 0)
                {
                    if (temp->left == NULL)
                    {
                        child = n;
                        temp->left = n;
                        if (l == 1)

                            ll = 1;
                        else if (r == 1)
                            rl = 1;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                        l = 1, r = 0, rr = 0, ll = 0, lr = 0, rl = 0;
                    }
                }
                else if (temp->data.compare(x) < 0)
                {
                    if (temp->right == NULL)
                    {
                        child = n;
                        temp->right = n;
                        if (l == 1)
                            lr = 1;
                        else if (r == 1)
                            rr = 1;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                        r = 1, l = 0, rr = 0, ll = 0, lr = 0, rl = 0;
                    }
                }
            }
            parent = findParent(n);
            grandparent = findParent(parent);
        }
        cout << "Before Rotate : ";
        display();
        balance();
        cout << "After Rotate : ";
    }

    void search(string x)
    {
        if (root == NULL)
            root = new AvlNode(x);
        else
        {
            AvlNode *n = new AvlNode(x);
            AvlNode *temp = root;
            while (1)
            {
                if (temp->data.compare(x) == 0)
                {
                    cout << "The word is found" << temp->data << " at location : " << temp << endl;

                    break;
                }
                else if (temp->data.compare(x) > 0)
                {
                    if (temp->left == NULL)
                        cout << "The word doesn'texist." << endl;

                    else
                        temp = temp->left;
                }
                else if (temp->data.compare(x) < 0)
                {
                    if (temp->right == NULL)
                        cout << "The word doesn'texist." << endl;

                    else
                        temp = temp->right;
                }
            }
        }
    }
    void display()

    {
        if (root == NULL)
        {
            cout << "AVL Tree is Empty." << endl;
            return;
        }
        Queue q;
        q.enqueue(root);
        while (q.front != NULL)
        {
            AvlNode *temp = q.dequeue();
            cout << temp->data << "|";
            if (temp->left != NULL)
                q.enqueue(temp->left);
            if (temp->right != NULL)
                q.enqueue(temp->right);
        }
        cout << endl;
    }
};
int main()
{
    AVL avl;
    while (1)
    {
        cout << "Enter 1-Insert in AVL Tree | 2-Search fromAVL Tree | 0-EXIT : " << endl;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter Word to be Inserted in AVL Tree :" << endl;

            string x;
            cin >> x;
            avl.insert(x);
        }
        else if (ch == 2)

        {
            cout << "Enter Word to be Searched in AVL Tree :" << endl;

            string x;
            cin >> x;
            avl.search(x);
        }
        else if (ch == 0)
        {
            cout << "EXITING." << endl;
            break;
        }
        avl.display();
    }
    return 0;
}
