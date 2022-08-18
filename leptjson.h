#ifndef LEPTJSON_H_

#define LEPTJSON_H_

//声明枚举类型（enumeration type)
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_ARRAY, LEPT_OBJECT} lept_type;

typedef struct {
	lept_type type;
}lept_value;

enum {                          //lept_parse返回值
    LEPT_PARSE_OK = 0,              //正常
    LEPT_PARSE_EXPECT_VALUE,        //只有空白
    LEPT_PARSE_INVALID_VALUE,       //无效的值
    LEPT_PARSE_ROOT_NOT_SINGULAR    //值不唯一
};

int lept_parse(lept_value* v, const char* json);

lept_type lept_get_type(const lept_value* v);

#endif 