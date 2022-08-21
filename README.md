# 一个轻量化的JSON库

# 数据结构设计

```c
typedef struct lept_value lept_value;
typedef struct lept_member lept_member;

struct lept_value{
    union {
        struct { lept_member* m; size_t size; } o;
        struct { lept_value* e; size_t size; } a;
        struct { char* s; size_t len; } s;
        double n;
    }u;
	lept_type type;
};

struct lept_member {
    char* k; size_t klen;   /* member key string, key string length */
    lept_value v;           /* member value */
};
```

# API
### 解析json字符串
```c
int lept_parse(lept_value* v, const char* json);
```

### 生成json字符串
```c
char* lept_stringify(const lept_value* v, size_t* length);
```

### 其他接口
```c
void lept_free(lept_value* v);

lept_type lept_get_type(const lept_value* v);

#define lept_set_null(v) lept_free(v)

int lept_get_boolean(const lept_value* v);
void lept_set_boolean(lept_value* v, int b);

double lept_get_number(const lept_value* v);
void lept_set_number(lept_value* v, double n);

const char* lept_get_string(const lept_value* v);
size_t lept_get_string_length(const lept_value* v);
void lept_set_string(lept_value* v, const char* s, size_t len);

size_t lept_get_array_size(const lept_value* v);
lept_value* lept_get_array_element(const lept_value* v, size_t index);

size_t lept_get_object_size(const lept_value* v);
const char* lept_get_object_key(const lept_value* v, size_t index);
size_t lept_get_object_key_length(const lept_value* v, size_t index);
lept_value* lept_get_object_value(const lept_value* v, size_t index);
```