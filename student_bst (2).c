/*
 * PROJECT 2: Student Record Search System Using a Binary Search Tree
 * Language: C
 * Concepts: BST insertion, search, deletion, traversals, duplicate handling.
 *
 * Compile: gcc student_bst.c -o student_bst
 * Run:     ./student_bst
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define DEPT_LEN 30

typedef struct Student {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    struct Student *left, *right;
} Student;

int comparisons = 0;

Student *createNode(int id, const char *name, const char *department) {
    Student *node = (Student *)malloc(sizeof(Student));
    if (!node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->id = id;
    snprintf(node->name, NAME_LEN, "%s", name);
    snprintf(node->department, DEPT_LEN, "%s", department);
    node->left = node->right = NULL;
    return node;
}

Student *insert(Student *root, int id, const char *name, const char *department) {
    if (root == NULL) return createNode(id, name, department);

    comparisons++;
    if (id < root->id)
        root->left = insert(root->left, id, name, department);
    else if (id > root->id)
        root->right = insert(root->right, id, name, department);
    else
        printf("Duplicate enrolment ID %d rejected. ID must be unique.\n", id);
    return root;
}

Student *search(Student *root, int id) {
    while (root != NULL) {
        comparisons++;
        if (id == root->id) return root;
        if (id < root->id) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Student *minimumNode(Student *root) {
    while (root && root->left) root = root->left;
    return root;
}

Student *deleteNode(Student *root, int id) {
    Student *temp;
    if (root == NULL) return NULL;

    comparisons++;
    if (id < root->id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    } else {
        /* Case 1: leaf node; Case 2: node with one child. */
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Case 3: two children - replace with inorder successor. */
        temp = minimumNode(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        strcpy(root->department, temp->department);
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

void inorder(Student *root) {
    if (!root) return;
    inorder(root->left);
    printf("%-8d %-20s %-15s\n", root->id, root->name, root->department);
    inorder(root->right);
}

void preorder(Student *root) {
    if (!root) return;
    printf("%d ", root->id);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Student *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->id);
}

void freeTree(Student *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void insertSampleRecords(Student **root) {
    /* Ten sample records, inserted in a balanced-looking order. */
    *root = insert(*root, 104, "Aarav Sharma", "CSE");
    *root = insert(*root, 102, "Diya Gupta", "ECE");
    *root = insert(*root, 108, "Kabir Singh", "CSE");
    *root = insert(*root, 101, "Meera Patel", "IT");
    *root = insert(*root, 103, "Rohan Kumar", "CSE");
    *root = insert(*root, 106, "Anaya Verma", "ECE");
    *root = insert(*root, 110, "Ishaan Das", "IT");
    *root = insert(*root, 105, "Sara Khan", "CSE");
    *root = insert(*root, 107, "Vivaan Rao", "IT");
    *root = insert(*root, 109, "Ira Joshi", "ECE");
}

int main(void) {
    Student *root = NULL, *found;
    int choice, id;
    char name[NAME_LEN], department[DEPT_LEN];

    insertSampleRecords(&root);
    do {
        printf("\n===== STUDENT RECORD SEARCH SYSTEM =====\n");
        printf("1. Insert student\n");
        printf("2. Search student by enrolment ID\n");
        printf("3. Delete student by enrolment ID\n");
        printf("4. Inorder traversal (sorted records)\n");
        printf("5. Preorder traversal\n");
        printf("6. Postorder traversal\n");
        printf("7. Show comparison counter\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            choice = 0;
        }

        switch (choice) {
            case 1:
                printf("Enter enrolment ID: ");
                scanf("%d", &id);
                printf("Enter student name (use underscores instead of spaces): ");
                scanf("%49s", name);
                printf("Enter department: ");
                scanf("%29s", department);
                comparisons = 0;
                {
                    int before = comparisons;
                    root = insert(root, id, name, department);
                    if (comparisons != before || root != NULL)
                        printf("Insertion operation completed.\n");
                }
                break;
            case 2:
                printf("Enter enrolment ID to search: ");
                scanf("%d", &id);
                comparisons = 0;
                found = search(root, id);
                if (found)
                    printf("Record found: ID=%d, Name=%s, Department=%s\n",
                           found->id, found->name, found->department);
                else
                    printf("Student with ID %d not found.\n", id);
                printf("Comparisons: %d\n", comparisons);
                break;
            case 3:
                printf("Enter enrolment ID to delete: ");
                scanf("%d", &id);
                comparisons = 0;
                if (search(root, id) == NULL) {
                    printf("Student with ID %d not found; nothing deleted.\n", id);
                } else {
                    comparisons = 0;
                    root = deleteNode(root, id);
                    printf("Student record deleted successfully.\n");
                }
                break;
            case 4:
                printf("\nRecords in ascending enrolment-ID order:\n");
                printf("%-8s %-20s %-15s\n", "ID", "Name", "Department");
                inorder(root);
                break;
            case 5:
                printf("Preorder IDs: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder IDs: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Comparisons in the most recent counted operation: %d\n",
                       comparisons);
                break;
            case 8:
                printf("Exiting Student Record Search System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    freeTree(root);
    return 0;
}
