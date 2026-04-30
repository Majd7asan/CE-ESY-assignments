#include <stdio.h>
#include <string.h>

#define SIZE 5   // اخترنا حجم صغير عمداً لتجربة Overflow

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

// تهيئة المخزن
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// تحقق إذا ممتلئ
int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// تحقق إذا فارغ
int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// كتابة في المخزن
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow!\n");
        return;
    }

    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

// قراءة من المخزن
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow!\n");
        return '\0';
    }

    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;

    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];

    // إدخال الاسم
    printf("Enter your name: ");
    scanf("%s", name);

    // إضافة CE-ESY
    strcat(name, "CE-ESY");

    // الكتابة في المخزن
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    // القراءة والطباعة
    printf("Output: ");
    while (!isEmpty(&cb)) {
        char c = read(&cb);
        if (c != '\0')
            printf("%c", c);
    }

    printf("\nBuffer is now empty.\n");

    return 0;
}
