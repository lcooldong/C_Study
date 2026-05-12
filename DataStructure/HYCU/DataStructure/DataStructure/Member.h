#ifdef __Member
#define __Meber

typedef struct {
    int no;
    char name[20];
} Member;

#define MEMBER_NO       1
#define MEMBER_NAME     2

int MemberNoCmp();

#endif