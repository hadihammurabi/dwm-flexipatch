#include <stdbool.h>

static unsigned int nexttag(bool skip_vacant);
static unsigned int prevtag(bool skip_vacant);
static void tagtonext(const Arg *arg);
static void tagtoprev(const Arg *arg);
static void viewnext(const Arg *arg);
static void viewprev(const Arg *arg);
