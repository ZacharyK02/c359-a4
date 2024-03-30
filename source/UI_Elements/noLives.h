/* GIMP RGBA C-Source image dump (noLives.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[96 * 30 * 4 + 1];
} noLives = {
  96, 30, 4,
  "\000\000\000\000\004\001\001\000\003\001\001\000\000\000\000\000\036\011\011\000\036\011\011\003\036\011\011\067\036\011"
  "\011\257\036\011\011\367\036\011\011\377\036\011\011\377\036\011\011\377\036\011\011\377"
  "\036\011\011\322\036\011\011Z\036\011\011\010\036\011\011\010\036\011\011Z\036\011\011\322\036"
  "\011\011\377\036\011\011\377\036\011\011\377\036\011\011\377\036\011\011\367\036\011\011\257"
  "\036\011\011\067\036\011\011\003\036\011\011\000\000\000\000\000\003\001\001\000\004\001\001\000\000\000\000\000\000\000\000"
  "\000\004\001\001\000\003\001\001\000\000\000\000\000\036\011\011\000\036\011\011\003\036\011\011\067\036\011\011\257"
  "\036\011\011\367\036\011\011\377\036\011\011\377\036\011\011\377\036\011\011\377\036\011\011"
  "\322\036\011\011Z\036\011\011\010\036\011\011\010\036\011\011Z\036\011\011\322\036\011\011\377"
  "\036\011\011\377\036\011\011\377\036\011\011\377\036\011\011\367\036\011\011\257\036\011\011"
  "\067\036\011\011\003\036\011\011\000\000\000\000\000\003\001\001\000\004\001\001\000\000\000\000\000\000\000\000\000\004\001\001\000"
  "\003\001\001\000\000\000\000\000\036\011\011\000\036\011\011\003\036\011\011\067\036\011\011\257\036\011\011"
  "\367\036\011\011\377\036\011\011\377\036\011\011\377\036\011\011\377\036\011\011\322\036"
  "\011\011Z\036\011\011\010\036\011\011\010\036\011\011Z\036\011\011\322\036\011\011\377\036\011"
  "\011\377\036\011\011\377\036\011\011\377\036\011\011\367\036\011\011\257\036\011\011\067\036"
  "\011\011\003\036\011\011\000\000\000\000\000\003\001\001\000\004\001\001\000\000\000\000\000\004\001\001\000\027\006\006\000\040\012"
  "\012\000\036\011\011\000!\013\013\000\036\011\011\002\035\010\010\065\035\010\010\256\035\010\010\367"
  "\035\010\010\377\035\010\010\377\035\010\010\377\035\010\010\377\035\010\010\323\035\010\010"
  "Y\035\010\010\010\035\010\010\010\035\010\010Y\035\010\010\323\035\010\010\377\035\010\010\377"
  "\035\010\010\377\035\010\010\377\035\010\010\367\035\010\010\256\035\010\010\065\036\011\011"
  "\002!\013\013\000\036\011\011\000\040\012\012\000\027\006\006\000\004\001\001\000\004\001\001\000\027\006\006\000\040\012"
  "\012\000\036\011\011\000!\013\013\000\036\011\011\002\035\010\010\065\035\010\010\256\035\010\010\367"
  "\035\010\010\377\035\010\010\377\035\010\010\377\035\010\010\377\035\010\010\323\035\010\010"
  "Y\035\010\010\010\035\010\010\010\035\010\010Y\035\010\010\323\035\010\010\377\035\010\010\377"
  "\035\010\010\377\035\010\010\377\035\010\010\367\035\010\010\256\035\010\010\065\036\011\011"
  "\002!\013\013\000\036\011\011\000\040\012\012\000\027\006\006\000\004\001\001\000\004\001\001\000\027\006\006\000\040\012"
  "\012\000\036\011\011\000!\013\013\000\036\011\011\002\035\010\010\065\035\010\010\256\035\010\010\367"
  "\035\010\010\377\035\010\010\377\035\010\010\377\035\010\010\377\035\010\010\323\035\010\010"
  "Y\035\010\010\010\035\010\010\010\035\010\010Y\035\010\010\323\035\010\010\377\035\010\010\377"
  "\035\010\010\377\035\010\010\377\035\010\010\367\035\010\010\256\035\010\010\065\036\011\011"
  "\002!\013\013\000\036\011\011\000\040\012\012\000\027\006\006\000\004\001\001\000\003\001\001\000\040\012\012\000\036"
  "\011\011\002\036\011\011\012\035\011\011\021\036\011\011\025#\015\015H$\015\015\265$\016\016\370"
  "$\015\015\377$\015\015\377$\015\015\377$\016\016\377$\016\016\326#\015\015h\037\012\012"
  "\032\037\012\012\032#\015\015h$\016\016\326$\016\016\377$\015\015\377$\015\015\377$\015\015"
  "\377$\016\016\370$\015\015\265#\015\015H\036\011\011\025\035\011\011\021\036\011\011\012\036"
  "\011\011\002\040\012\012\000\003\001\001\000\003\001\001\000\040\012\012\000\036\011\011\002\036\011\011\012\035"
  "\011\011\021\036\011\011\025#\015\015H$\015\015\265$\016\016\370$\015\015\377$\015\015\377"
  "$\015\015\377$\016\016\377$\016\016\326#\015\015h\037\012\012\032\037\012\012\032#\015\015"
  "h$\016\016\326$\016\016\377$\015\015\377$\015\015\377$\015\015\377$\016\016\370$\015\015"
  "\265#\015\015H\036\011\011\025\035\011\011\021\036\011\011\012\036\011\011\002\040\012\012\000\003"
  "\001\001\000\003\001\001\000\040\012\012\000\036\011\011\002\036\011\011\012\035\011\011\021\036\011\011\025"
  "#\015\015H$\015\015\265$\016\016\370$\015\015\377$\015\015\377$\015\015\377$\016\016\377"
  "$\016\016\326#\015\015h\037\012\012\032\037\012\012\032#\015\015h$\016\016\326$\016\016\377"
  "$\015\015\377$\015\015\377$\015\015\377$\016\016\370$\015\015\265#\015\015H\036\011\011"
  "\025\035\011\011\021\036\011\011\012\036\011\011\002\040\012\012\000\003\001\001\000\000\000\000\000\036\011\011"
  "\000\036\011\011\012\036\011\011\071\035\011\011m\036\011\011|*\022\022\227\066\032\032\325\071"
  "\034\034\373\071\034\034\377\071\034\034\377\071\034\034\377\071\034\034\377\070\033\033\350"
  "/\025\025\251\037\013\013}\037\013\013}/\025\025\251\070\033\033\350\071\034\034\377\071\034"
  "\034\377\071\034\034\377\071\034\034\377\071\034\034\373\066\032\032\325*\022\022\227\036"
  "\011\011|\035\011\011m\036\011\011\071\036\011\011\012\036\011\011\000\000\000\000\000\000\000\000\000\036\011"
  "\011\000\036\011\011\012\036\011\011\071\035\011\011m\036\011\011|*\022\022\227\066\032\032\325"
  "\071\034\034\373\071\034\034\377\071\034\034\377\071\034\034\377\071\034\034\377\070\033\033"
  "\350/\025\025\251\037\013\013}\037\013\013}/\025\025\251\070\033\033\350\071\034\034\377"
  "\071\034\034\377\071\034\034\377\071\034\034\377\071\034\034\373\066\032\032\325*\022\022"
  "\227\036\011\011|\035\011\011m\036\011\011\071\036\011\011\012\036\011\011\000\000\000\000\000\000\000\000"
  "\000\036\011\011\000\036\011\011\012\036\011\011\071\035\011\011m\036\011\011|*\022\022\227\066\032"
  "\032\325\071\034\034\373\071\034\034\377\071\034\034\377\071\034\034\377\071\034\034\377"
  "\070\033\033\350/\025\025\251\037\013\013}\037\013\013}/\025\025\251\070\033\033\350\071\034"
  "\034\377\071\034\034\377\071\034\034\377\071\034\034\377\071\034\034\373\066\032\032\325"
  "*\022\022\227\036\011\011|\035\011\011m\036\011\011\071\036\011\011\012\036\011\011\000\000\000\000"
  "\000\036\011\011\000$\015\015\000\035\011\011\020\035\011\011k\035\010\010\316\035\011\011\350,\023"
  "\023\353@!!\367I&&\376I&&\377I&&\377I&&\377J&&\377D##\372\063\030\030\356\037"
  "\012\012\346\037\012\012\346\063\030\030\356D##\372J&&\377I&&\377I&&\377I&&\377I"
  "&&\376@!!\367,\023\023\353\035\011\011\350\035\010\010\316\035\011\011k\035\011\011\020"
  "$\015\015\000\036\011\011\000\036\011\011\000$\015\015\000\035\011\011\020\035\011\011k\035\010\010\316"
  "\035\011\011\350,\023\023\353@!!\367I&&\376I&&\377I&&\377I&&\377J&&\377D##\372"
  "\063\030\030\356\037\012\012\346\037\012\012\346\063\030\030\356D##\372J&&\377I&&\377"
  "I&&\377I&&\377I&&\376@!!\367,\023\023\353\035\011\011\350\035\010\010\316\035\011\011"
  "k\035\011\011\020$\015\015\000\036\011\011\000\036\011\011\000$\015\015\000\035\011\011\020\035\011\011"
  "k\035\010\010\316\035\011\011\350,\023\023\353@!!\367I&&\376I&&\377I&&\377I&&\377"
  "J&&\377D##\372\063\030\030\356\037\012\012\346\037\012\012\346\063\030\030\356D##\372"
  "J&&\377I&&\377I&&\377I&&\377I&&\376@!!\367,\023\023\353\035\011\011\350\035\010"
  "\010\316\035\011\011k\035\011\011\020$\015\015\000\036\011\011\000\036\011\011\004\036\010\010\003\036"
  "\011\011\025\036\011\011y\036\011\011\346\036\011\011\377-\024\024\377B\"\"\377L((\377"
  "M((\377M((\377M((\377M))\377G%%\377\064\030\030\377\040\012\012\377\040\012\012\377"
  "\064\030\030\377G%%\377M))\377M((\377M((\377M((\377L((\377B\"\"\377-\024\024\377"
  "\036\011\011\377\036\011\011\346\036\011\011y\036\011\011\025\036\010\010\003\036\011\011\004\036"
  "\011\011\004\036\010\010\003\036\011\011\025\036\011\011y\036\011\011\346\036\011\011\377-\024\024"
  "\377B\"\"\377L((\377M((\377M((\377M((\377M))\377G%%\377\064\030\030\377\040\012"
  "\012\377\040\012\012\377\064\030\030\377G%%\377M))\377M((\377M((\377M((\377L((\377"
  "B\"\"\377-\024\024\377\036\011\011\377\036\011\011\346\036\011\011y\036\011\011\025\036\010"
  "\010\003\036\011\011\004\036\011\011\004\036\010\010\003\036\011\011\025\036\011\011y\036\011\011\346"
  "\036\011\011\377-\024\024\377B\"\"\377L((\377M((\377M((\377M((\377M))\377G%%\377"
  "\064\030\030\377\040\012\012\377\040\012\012\377\064\030\030\377G%%\377M))\377M((\377"
  "M((\377M((\377L((\377B\"\"\377-\024\024\377\036\011\011\377\036\011\011\346\036\011"
  "\011y\036\011\011\025\036\010\010\003\036\011\011\004\036\011\011=\035\010\010;#\014\014L+\022\022"
  "\227-\024\024\352.\024\024\377\066\032\032\377D##\377L''\377L((\377L((\377L((\377"
  "L((\377H%%\377;\035\035\377.\025\025\377.\025\025\377;\035\035\377H%%\377L((\377"
  "L((\377L((\377L((\377L''\377D##\377\066\032\032\377.\024\024\377-\024\024\352+\022"
  "\022\227#\014\014L\035\010\010;\036\011\011=\036\011\011=\035\010\010;#\014\014L+\022\022\227"
  "-\024\024\352.\024\024\377\066\032\032\377D##\377L''\377L((\377L((\377L((\377L("
  "(\377H%%\377;\035\035\377.\025\025\377.\025\025\377;\035\035\377H%%\377L((\377L("
  "(\377L((\377L((\377L''\377D##\377\066\032\032\377.\024\024\377-\024\024\352+\022"
  "\022\227#\014\014L\035\010\010;\036\011\011=\036\011\011=\035\010\010;#\014\014L+\022\022\227"
  "-\024\024\352.\024\024\377\066\032\032\377D##\377L''\377L((\377L((\377L((\377L("
  "(\377H%%\377;\035\035\377.\025\025\377.\025\025\377;\035\035\377H%%\377L((\377L("
  "(\377L((\377L((\377L''\377D##\377\066\032\032\377.\024\024\377-\024\024\352+\022"
  "\022\227#\014\014L\035\010\010;\036\011\011=\036\011\011\266\035\010\010\265#\015\015\273"
  "\065\032\032\330@!!\367C\"\"\377E##\377I&&\377L((\377L((\377L((\377L((\377L"
  "((\377K''\377F$$\377C\"\"\377C\"\"\377F$$\377K''\377L((\377L((\377L((\377"
  "L((\377L((\377I&&\377E##\377C\"\"\377@!!\367\065\032\032\330#\015\015\273\035\010"
  "\010\265\036\011\011\266\036\011\011\266\035\010\010\265#\015\015\273\065\032\032\330@!"
  "!\367C\"\"\377E##\377I&&\377L((\377L((\377L((\377L((\377L((\377K''\377F$"
  "$\377C\"\"\377C\"\"\377F$$\377K''\377L((\377L((\377L((\377L((\377L((\377"
  "I&&\377E##\377C\"\"\377@!!\367\065\032\032\330#\015\015\273\035\010\010\265\036\011"
  "\011\266\036\011\011\266\035\010\010\265#\015\015\273\065\032\032\330@!!\367C\"\"\377"
  "E##\377I&&\377L((\377L((\377L((\377L((\377L((\377K''\377F$$\377C\"\"\377"
  "C\"\"\377F$$\377K''\377L((\377L((\377L((\377L((\377L((\377I&&\377E##\377"
  "C\"\"\377@!!\367\065\032\032\330#\015\015\273\035\010\010\265\036\011\011\266\036\011"
  "\011\371\035\010\010\371$\015\015\371\071\033\033\374I&&\376L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377K((\377L''\377L''\377K((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377H&&\376\070\033"
  "\033\374#\015\015\371\034\010\010\371\035\010\010\371\035\010\010\371\034\010\010\371#\015"
  "\015\371\070\033\033\374H&&\376L((\377L((\377L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377K((\377L''\377L''\377K((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377H&&\376\070\033\033\374#\015\015\371\034\010"
  "\010\371\035\010\010\371\035\010\010\371\034\010\010\371#\015\015\371\070\033\033\374H&"
  "&\376L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377K((\377"
  "L''\377L''\377K((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377I&&\376\071\033\033\374$\015\015\371\035\010\010\371\036\011\011\371\036"
  "\011\011\377\035\010\010\377$\015\015\377\071\033\033\377I&&\377M((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377I&&\377;\035"
  "\035\377(\021\021\377#\014\014\377#\015\015\377#\015\015\377#\014\014\377(\021\021\377"
  ";\035\035\377I&&\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377I&&\377;\035\035\377(\021\021\377#\014\014\377#\015\015"
  "\377#\015\015\377#\014\014\377(\021\021\377;\035\035\377I&&\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377M((\377I&&\377\071"
  "\033\033\377$\015\015\377\035\010\010\377\036\011\011\377\036\011\011\377\035\010\010\377"
  "$\015\015\377\071\033\033\377I&&\377M((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377J''\377C\"\"\377:\035\035\377\071\034"
  "\034\377\071\034\034\377\071\034\034\377\071\034\034\377:\035\035\377C\"\"\377J''\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377J''\377C\"\"\377:\035\035\377\071\034\034\377\071\034\034\377\071\034\034\377"
  "\071\034\034\377:\035\035\377C\"\"\377J''\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377M((\377I&&\377\071\033\033\377$\015\015"
  "\377\035\010\010\377\036\011\011\377\036\011\011\377\035\010\010\377$\015\015\377\071\033"
  "\033\377I&&\377M((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377K''\377H%%\377E##\377D##\377D##\377D##\377D##\377E#"
  "#\377H%%\377K''\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377K''\377H%%\377E##\377D##\377D##\377D##\377D##\377"
  "E##\377H%%\377K''\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377M((\377I&&\377\071\033\033\377$\015\015\377\035\010\010\377"
  "\036\011\011\377\036\011\011\377\035\010\010\377$\015\015\377\071\033\033\377I&&\377M("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377J''\377B\"\"\377\071\034\034\377\067\033\033\377\067\033\033\377\067\033\033\377"
  "\067\033\033\377\071\034\034\377B\"\"\377J''\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377J''\377B\"\"\377\071\034\034"
  "\377\067\033\033\377\067\033\033\377\067\033\033\377\067\033\033\377\071\034\034\377B\""
  "\"\377J''\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377M((\377I&&\377\071\033\033\377$\015\015\377\035\010\010\377\036\011\011"
  "\377\036\011\011\377\035\010\010\377$\015\015\377\071\033\033\377I&&\377M))\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377M))\377I&&\377"
  ":\035\035\377'\020\020\377\"\014\014\377\"\014\014\377\"\014\014\377\"\014\014\377'\020"
  "\020\377:\035\035\377I&&\377M))\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377M))\377I&&\377:\035\035\377'\020\020\377\"\014\014\377"
  "\"\014\014\377\"\014\014\377\"\014\014\377'\020\020\377:\035\035\377I&&\377M))\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377M))\377"
  "I&&\377\071\033\033\377$\015\015\377\035\010\010\377\036\011\011\377\036\011\011\372\035"
  "\010\010\372$\015\015\373\071\033\033\374H&&\376L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377H&&\376\070\033\033\374#\015"
  "\015\373\035\010\010\372\035\010\010\372\035\010\010\372\035\010\010\372#\015\015\373\070"
  "\033\033\374H&&\376L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377H&&\376\070\033\033\374#\015\015\373\035\010\010\372\035"
  "\010\010\372\035\010\010\372\035\010\010\372#\015\015\373\070\033\033\374H&&\376L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "H&&\376\071\033\033\374$\015\015\373\035\010\010\372\036\011\011\372\036\011\011\261\035"
  "\010\010\260#\015\015\267\065\031\031\325@\040\040\366B\"\"\377D##\377I&&\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377L((\377L((\377I&&\377D##\377B\"\"\377@\040\040\366\065\031"
  "\031\325#\015\015\267\035\010\010\260\036\011\011\261\036\011\011\261\035\010\010\260#\015"
  "\015\267\065\031\031\325@\040\040\366B\"\"\377D##\377I&&\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L("
  "(\377L((\377L((\377I&&\377D##\377B\"\"\377@\040\040\366\065\031\031\325#\015\015"
  "\267\035\010\010\260\036\011\011\261\036\011\011\261\035\010\010\260#\015\015\267\065\031"
  "\031\325@\040\040\366B\"\"\377D##\377I&&\377L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377I&&\377D##\377B\"\"\377@\040\040\366\065\031\031\325#\015\015\267\035\010\010"
  "\260\036\011\011\261\036\011\011\065\035\010\010\064\"\014\014E*\021\021\223+\022\022\351"
  ",\023\023\377\065\031\031\377D##\377K((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377K((\377D#"
  "#\377\065\031\031\377,\023\023\377+\022\022\351*\021\021\223\"\014\014E\035\010\010\064"
  "\036\011\011\065\036\011\011\065\035\010\010\064\"\014\014E*\021\021\223+\022\022\351,\023\023"
  "\377\065\031\031\377D##\377K((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377K((\377D##\377\065"
  "\031\031\377,\023\023\377+\022\022\351*\021\021\223\"\014\014E\035\010\010\064\036\011\011"
  "\065\036\011\011\065\035\010\010\064\"\014\014E*\021\021\223+\022\022\351,\023\023\377\065"
  "\031\031\377D##\377K((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377K((\377D##\377\065\031\031"
  "\377,\023\023\377+\022\022\351*\021\021\223\"\014\014E\035\010\010\064\036\011\011\065\036"
  "\011\011\001\035\010\010\001\036\010\010\022\036\010\010w\035\010\010\345\036\011\011\377-\024\024"
  "\376B\"\"\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377B\"\"\377-\024\024\376"
  "\036\011\011\377\035\010\010\345\036\010\010w\036\010\010\022\035\010\010\001\036\011\011\001\036"
  "\011\011\001\035\010\010\001\036\010\010\022\036\010\010w\035\010\010\345\036\011\011\377-\024\024"
  "\376B\"\"\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377B\"\"\377-\024\024\376"
  "\036\011\011\377\035\010\010\345\036\010\010w\036\010\010\022\035\010\010\001\036\011\011\001\036"
  "\011\011\001\035\010\010\001\036\010\010\022\036\010\010w\035\010\010\345\036\011\011\377-\024\024"
  "\376B\"\"\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377B\"\"\377-\024\024\376"
  "\036\011\011\377\035\010\010\345\036\010\010w\036\010\010\022\035\010\010\001\036\011\011\001\026"
  "\005\005\000\036\011\011\000\036\011\011\020\036\011\011i\035\011\011\313\036\011\011\346,\023\023"
  "\351@\040\040\366H&&\376I&&\377J''\377L((\377L((\377L((\377L((\377L((\377L"
  "((\377L((\377L((\377L((\377L((\377J''\377I&&\377H&&\376@\040\040\366,\023\023"
  "\351\036\011\011\346\035\011\011\313\036\011\011i\036\011\011\020\036\011\011\000\026\005\005\000"
  "\026\005\005\000\036\011\011\000\036\011\011\020\036\011\011i\035\011\011\313\036\011\011\346,\023"
  "\023\351@\040\040\366H&&\376I&&\377J''\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377J''\377I&&\377H&&\376@\040\040\366,\023\023"
  "\351\036\011\011\346\035\011\011\313\036\011\011i\036\011\011\020\036\011\011\000\026\005\005\000"
  "\026\005\005\000\036\011\011\000\036\011\011\020\036\011\011i\035\011\011\313\036\011\011\346,\023"
  "\023\351@\040\040\366H&&\376I&&\377J''\377L((\377L((\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377J''\377I&&\377H&&\376@\040\040\366,\023\023"
  "\351\036\011\011\346\035\011\011\313\036\011\011i\036\011\011\020\036\011\011\000\026\005\005\000"
  "\000\000\000\000\036\011\011\000\036\011\011\011\036\011\011\067\035\011\011i\036\011\011w*\021\021\223"
  "\065\031\031\324\070\033\033\373:\034\034\377B!!\377J''\377L((\377L((\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377J''\377B!!\377:\034\034\377\070\033\033\373"
  "\065\031\031\324*\021\021\223\036\011\011w\035\011\011i\036\011\011\067\036\011\011\011\036\011"
  "\011\000\000\000\000\000\000\000\000\000\036\011\011\000\036\011\011\011\036\011\011\067\035\011\011i\036\011"
  "\011w*\021\021\223\065\031\031\324\070\033\033\373:\034\034\377B!!\377J''\377L((\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377J''\377B!!\377:\034\034\377"
  "\070\033\033\373\065\031\031\324*\021\021\223\036\011\011w\035\011\011i\036\011\011\067\036"
  "\011\011\011\036\011\011\000\000\000\000\000\000\000\000\000\036\011\011\000\036\011\011\011\036\011\011\067\035"
  "\011\011i\036\011\011w*\021\021\223\065\031\031\324\070\033\033\373:\034\034\377B!!\377"
  "J''\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377J''\377B!"
  "!\377:\034\034\377\070\033\033\373\065\031\031\324*\021\021\223\036\011\011w\035\011\011"
  "i\036\011\011\067\036\011\011\011\036\011\011\000\000\000\000\000\003\001\001\000\037\011\011\000\036\011\011"
  "\002\036\011\011\011\035\011\011\020\036\011\011\024\"\014\014E#\015\015\266\"\014\014\371&\017"
  "\017\377\071\033\033\377H%%\377L((\377L((\377L((\377L((\377L((\377L((\377L(("
  "\377L((\377H%%\377\071\033\033\377&\017\017\377\"\014\014\371#\015\015\266\"\014\014"
  "E\036\011\011\024\035\011\011\020\036\011\011\011\036\011\011\002\037\011\011\000\003\001\001\000\003\001\001"
  "\000\037\011\011\000\036\011\011\002\036\011\011\011\035\011\011\020\036\011\011\024\"\014\014E#\015"
  "\015\266\"\014\014\371&\017\017\377\071\033\033\377H%%\377L((\377L((\377L((\377L"
  "((\377L((\377L((\377L((\377L((\377H%%\377\071\033\033\377&\017\017\377\"\014\014"
  "\371#\015\015\266\"\014\014E\036\011\011\024\035\011\011\020\036\011\011\011\036\011\011\002\037"
  "\011\011\000\003\001\001\000\003\001\001\000\037\011\011\000\036\011\011\002\036\011\011\011\035\011\011\020\036"
  "\011\011\024\"\014\014E#\015\015\266\"\014\014\371&\017\017\377\071\033\033\377H%%\377"
  "L((\377L((\377L((\377L((\377L((\377L((\377L((\377L((\377H%%\377\071\033\033"
  "\377&\017\017\377\"\014\014\371#\015\015\266\"\014\014E\036\011\011\024\035\011\011\020\036"
  "\011\011\011\036\011\011\002\037\011\011\000\003\001\001\000\003\001\001\000\000\000\000\000\035\011\011\000\036\011"
  "\011\000\035\010\010\000\034\007\007\002\035\010\010\064\035\010\010\254\033\010\010\364!\013\013\372"
  "\066\032\032\373H%%\376L((\377L((\377L((\377L((\377L((\377L((\377L((\377L(("
  "\377H%%\376\066\032\032\373!\013\013\372\033\010\010\364\035\010\010\254\035\010\010\064"
  "\034\007\007\002\035\010\010\000\036\011\011\000\035\011\011\000\000\000\000\000\003\001\001\000\003\001\001\000\000\000\000"
  "\000\035\011\011\000\036\011\011\000\035\010\010\000\034\007\007\002\035\010\010\064\035\010\010\254\033"
  "\010\010\364!\013\013\372\066\032\032\373H%%\376L((\377L((\377L((\377L((\377L(("
  "\377L((\377L((\377L((\377H%%\376\066\032\032\373!\013\013\372\033\010\010\364\035"
  "\010\010\254\035\010\010\064\034\007\007\002\035\010\010\000\036\011\011\000\035\011\011\000\000\000\000\000"
  "\003\001\001\000\003\001\001\000\000\000\000\000\035\011\011\000\036\011\011\000\035\010\010\000\034\007\007\002\035\010"
  "\010\064\035\010\010\254\033\010\010\364!\013\013\372\066\032\032\373H%%\376L((\377L("
  "(\377L((\377L((\377L((\377L((\377L((\377L((\377H%%\376\066\032\032\373!\013\013"
  "\372\033\010\010\364\035\010\010\254\035\010\010\064\034\007\007\002\035\010\010\000\036\011\011\000"
  "\035\011\011\000\000\000\000\000\003\001\001\000\000\000\000\000\000\000\000\000\003\001\001\000\023\004\004\000\036\011\011\000\036"
  "\011\011\002\036\011\011'\036\011\011|\035\010\010\261\"\014\014\273\064\030\030\325@\040\040"
  "\365B\"\"\377D##\377I&&\377L((\377L((\377I&&\377D##\377B\"\"\377@\040\040\365"
  "\064\030\030\325\"\014\014\273\035\010\010\261\036\011\011|\036\011\011'\036\011\011\002\036"
  "\011\011\000\023\004\004\000\003\001\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\003\001\001\000\023\004\004"
  "\000\036\011\011\000\036\011\011\002\036\011\011'\036\011\011|\035\010\010\261\"\014\014\273\064"
  "\030\030\325@\040\040\365B\"\"\377D##\377I&&\377L((\377L((\377I&&\377D##\377"
  "B\"\"\377@\040\040\365\064\030\030\325\"\014\014\273\035\010\010\261\036\011\011|\036\011"
  "\011'\036\011\011\002\036\011\011\000\023\004\004\000\003\001\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\003\001\001\000\023\004\004\000\036\011\011\000\036\011\011\002\036\011\011'\036\011\011|\035\010\010\261"
  "\"\014\014\273\064\030\030\325@\040\040\365B\"\"\377D##\377I&&\377L((\377L((\377"
  "I&&\377D##\377B\"\"\377@\040\040\365\064\030\030\325\"\014\014\273\035\010\010\261"
  "\036\011\011|\036\011\011'\036\011\011\002\036\011\011\000\023\004\004\000\003\001\001\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\036\011\011\000\036\011\011\001\036\011\011\015\036\011"
  "\011)\035\010\010\070\"\014\014G+\022\022\216-\024\024\344-\024\024\376\064\031\031\377C"
  "\"\"\377K((\377K((\377C\"\"\377\064\031\031\377-\024\024\376-\024\024\344+\022\022"
  "\216\"\014\014G\035\010\010\070\036\011\011)\036\011\011\015\036\011\011\001\036\011\011\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\036\011\011\000\036"
  "\011\011\001\036\011\011\015\036\011\011)\035\010\010\070\"\014\014G+\022\022\216-\024\024\344"
  "-\024\024\376\064\031\031\377C\"\"\377K((\377K((\377C\"\"\377\064\031\031\377-\024"
  "\024\376-\024\024\344+\022\022\216\"\014\014G\035\010\010\070\036\011\011)\036\011\011\015"
  "\036\011\011\001\036\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\036\011\011\000\036\011\011\001\036\011\011\015\036\011\011)\035\010\010\070\""
  "\014\014G+\022\022\216-\024\024\344-\024\024\376\064\031\031\377C\"\"\377K((\377K(("
  "\377C\"\"\377\064\031\031\377-\024\024\376-\024\024\344+\022\022\216\"\014\014G\035\010"
  "\010\070\036\011\011)\036\011\011\015\036\011\011\001\036\011\011\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\037\011\011\000\036\011\011\001"
  "\036\011\011\003\034\007\007\002\036\012\012\021\036\011\011m\036\011\011\337\035\011\011\377*\022"
  "\022\377@!!\377L((\377L((\377@!!\377*\022\022\377\035\011\011\377\036\011\011\337"
  "\036\011\011m\036\012\012\021\034\007\007\002\036\011\011\003\036\011\011\001\037\011\011\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\037\011\011\000\036\011\011\001\036\011\011\003\034\007\007\002\036\012\012\021\036\011\011m\036\011\011"
  "\337\035\011\011\377*\022\022\377@!!\377L((\377L((\377@!!\377*\022\022\377\035\011"
  "\011\377\036\011\011\337\036\011\011m\036\012\012\021\034\007\007\002\036\011\011\003\036\011\011\001"
  "\037\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\037\011\011\000\036\011\011\001\036\011\011\003\034\007\007\002\036\012\012\021"
  "\036\011\011m\036\011\011\337\035\011\011\377*\022\022\377@!!\377L((\377L((\377@!!\377"
  "*\022\022\377\035\011\011\377\036\011\011\337\036\011\011m\036\012\012\021\034\007\007\002\036\011"
  "\011\003\036\011\011\001\037\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\006\001\001\000\000\000\000\000\035\011\011\000\036\011\011\000\035\010\010"
  "\000\035\011\011\015\035\011\011a\035\011\011\307\035\010\010\346)\021\021\353>\037\037\366"
  "H&&\376H&&\376>\037\037\366)\021\021\353\035\010\010\346\035\011\011\307\035\011\011a"
  "\035\011\011\015\035\010\010\000\036\011\011\000\035\011\011\000\000\000\000\000\006\001\001\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\006\001\001\000\000\000\000\000\035\011"
  "\011\000\036\011\011\000\035\010\010\000\035\011\011\015\035\011\011a\035\011\011\307\035\010\010\346"
  ")\021\021\353>\037\037\366H&&\376H&&\376>\037\037\366)\021\021\353\035\010\010\346\035"
  "\011\011\307\035\011\011a\035\011\011\015\035\010\010\000\036\011\011\000\035\011\011\000\000\000\000\000"
  "\006\001\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\006\001\001\000\000\000\000\000\035\011\011\000\036\011\011\000\035\010\010\000\035\011\011\015\035\011\011a\035"
  "\011\011\307\035\010\010\346)\021\021\353>\037\037\366H&&\376H&&\376>\037\037\366)\021"
  "\021\353\035\010\010\346\035\011\011\307\035\011\011a\035\011\011\015\035\010\010\000\036\011"
  "\011\000\035\011\011\000\000\000\000\000\006\001\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\036\011\011\000\036\011"
  "\011\007\036\011\011\064\036\011\011i\035\010\010y)\021\021\222\065\031\031\320\071\034\034\373"
  "\071\034\034\373\065\031\031\320)\021\021\222\035\010\010y\036\011\011i\036\011\011\064\036"
  "\011\011\007\036\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\036\011\011\000\036\011\011\007\036\011\011\064\036\011\011i\035\010\010y)\021\021\222\065\031"
  "\031\320\071\034\034\373\071\034\034\373\065\031\031\320)\021\021\222\035\010\010y\036\011"
  "\011i\036\011\011\064\036\011\011\007\036\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\036\011\011\000\036\011\011\007\036\011\011\064\036\011\011i\035\010"
  "\010y)\021\021\222\065\031\031\320\071\034\034\373\071\034\034\373\065\031\031\320)\021\021"
  "\222\035\010\010y\036\011\011i\036\011\011\064\036\011\011\007\036\011\011\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\035\011\011\000\036\011\011\001\036\011\011"
  "\011\036\011\011\021\035\010\010\022#\014\014<$\015\015\254$\016\016\370$\016\016\370$\015"
  "\015\254#\014\014<\035\010\010\022\036\011\011\021\036\011\011\011\036\011\011\001\035\011\011\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\035\011\011\000\036\011"
  "\011\001\036\011\011\011\036\011\011\021\035\010\010\022#\014\014<$\015\015\254$\016\016\370$"
  "\016\016\370$\015\015\254#\014\014<\035\010\010\022\036\011\011\021\036\011\011\011\036\011\011"
  "\001\035\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\035\011"
  "\011\000\036\011\011\001\036\011\011\011\036\011\011\021\035\010\010\022#\014\014<$\015\015\254$"
  "\016\016\370$\016\016\370$\015\015\254#\014\014<\035\010\010\022\036\011\011\021\036\011\011"
  "\011\036\011\011\001\035\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\037\011\011\000\036\011\011\000\036\011\011\000\034\010\010\000\035\010\010+\035"
  "\010\010\243\035\010\010\367\035\010\010\367\035\010\010\243\035\010\010+\034\010\010\000\036"
  "\011\011\000\036\011\011\000\037\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\037\011\011\000\036\011\011\000\036\011\011\000\034\010\010"
  "\000\035\010\010+\035\010\010\243\035\010\010\367\035\010\010\367\035\010\010\243\035\010\010"
  "+\034\010\010\000\036\011\011\000\036\011\011\000\037\011\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\037\011\011\000\036\011\011\000\036\011"
  "\011\000\034\010\010\000\035\010\010+\035\010\010\243\035\010\010\367\035\010\010\367\035\010\010"
  "\243\035\010\010+\034\010\010\000\036\011\011\000\036\011\011\000\037\011\011\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\002\001\001\000\003\001\001\000\000\000\000"
  "\000\023\004\004\000\036\011\011\000\036\011\011,\036\011\011\244\036\011\011\367\036\011\011\367\036"
  "\011\011\244\036\011\011,\036\011\011\000\023\004\004\000\000\000\000\000\003\001\001\000\002\001\001\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\002\001\001\000\003\001\001\000\000\000\000\000"
  "\023\004\004\000\036\011\011\000\036\011\011,\036\011\011\244\036\011\011\367\036\011\011\367\036"
  "\011\011\244\036\011\011,\036\011\011\000\023\004\004\000\000\000\000\000\003\001\001\000\002\001\001\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\002\001\001\000\003\001\001\000\000\000\000\000"
  "\023\004\004\000\036\011\011\000\036\011\011,\036\011\011\244\036\011\011\367\036\011\011\367\036"
  "\011\011\244\036\011\011,\036\011\011\000\023\004\004\000\000\000\000\000\003\001\001\000\002\001\001\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
};

