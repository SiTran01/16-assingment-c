#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== Cấu trúc cây =====
typedef struct Cars {
    char model[50];
    struct Cars *child;
    struct Cars *sibling;
    struct Cars *parent;
} Cars;

// ===== Tạo node =====
Cars *createCar(const char *model) {
    Cars *newCar = (Cars *)malloc(sizeof(Cars));
    strcpy(newCar->model, model);  // <-- chỗ này m bị sai ở bản trước: phải là strcpy, ko phải strcmp
    newCar->child = NULL;
    newCar->sibling = NULL;
    newCar->parent = NULL;
    return newCar;
}

// ===== Thêm node con =====
void addChild(Cars *parent, Cars *child) {
    child->parent = parent;
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Cars *temp = parent->child;
        while (temp->sibling != NULL)
            temp = temp->sibling;
        temp->sibling = child;
    }
}

// ===== Duyệt cây để tìm xe theo tên =====
void findCarInfo(Cars *root, const char *name) {
    if (root == NULL)
        return;

    if (strcmp(root->model, name) == 0) {
        printf("\n✅ Found car: %s\n", root->model);

        if (root->parent != NULL)
            printf("Type: %s\n", root->parent->model);

        if (root->parent && root->parent->parent)
            printf("Manufacturer: %s\n", root->parent->parent->model);

        if (root->parent == NULL)
            printf("This is the root of the car tree.\n");

        return;
    }

    findCarInfo(root->child, name);
    findCarInfo(root->sibling, name);
}

// ===== Giải phóng bộ nhớ =====
void freeTree(Cars *root) {
    if (root == NULL) return;
    freeTree(root->child);
    freeTree(root->sibling);
    free(root);
}

// ===== Tạo cây ví dụ =====
Cars *buildCarTree() {
    Cars *root = createCar("Cars");

    Cars *toyota = createCar("Toyota");
    Cars *honda = createCar("Honda");
    addChild(root, toyota);
    addChild(root, honda);

    // Toyota types
    Cars *sedan = createCar("Sedan");
    Cars *suv = createCar("SUV");
    addChild(toyota, sedan);
    addChild(toyota, suv);

    // Toyota Sedan models
    Cars *camry = createCar("Camry");
    Cars *corolla = createCar("Corolla");
    addChild(sedan, camry);
    addChild(sedan, corolla);

    // Toyota SUV models
    Cars *fortuner = createCar("Fortuner");
    addChild(suv, fortuner);

    // Honda
    Cars *sedanH = createCar("Sedan");
    addChild(honda, sedanH);

    Cars *city = createCar("City");
    addChild(sedanH, city);

    return root;
}

// ===== MAIN =====
int main() {
    Cars *root = buildCarTree();
    char name[50];

    printf("=== Car Info Finder ===\n");
    printf("Enter car model name (e.g., Camry, Fortuner, City): ");
    scanf(" %[^\n]", name);

    findCarInfo(root, name);

    freeTree(root);
    return 0;
}
