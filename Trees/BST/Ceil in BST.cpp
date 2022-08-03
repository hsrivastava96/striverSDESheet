// { Driver Code Starts
// Initial Template for C
/*
    Algo:
    If input is greater than current root then move to right
    If input is lesser than current root 
        then set ceil to current node and move to left

    do this until root is != NULL

    return ceil
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define N 1000000

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNewNode(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *tree, int val) {

    if (tree == NULL) {
        return createNewNode(val);
    }

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

struct Node *convert_str_to_num(char str[]) {
    char *token = strtok(str, " ");

    struct Node *root = NULL;

    char c[2] = {'N'};
    while (token != NULL) {
        if (strcmp(c, token) != 0) {
            int num = atoi(token);
            root = insert(root, num);
        }
        token = strtok(NULL, " ");
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


 // } Driver Code Ends
// User function Template for C

int findCeil(struct Node* root, int input) 
{
    // your code here
    int c = -1;
    while(root)
    {
        if(root->data == input)
            return root->data;
        else if(input > root->data)
            root = root->right;
        else
        {
            c = root->data;
            root = root->left;
        }
    }
    return c;
}

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        while ((getchar()) != '\n')
            ;
        char str[N];
        scanf("%[^\n]s", str);

        int x;
        scanf("%d", &x);

        struct Node *root = NULL;

        root = convert_str_to_num(str);

        int ans = findCeil(root, x);

        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends