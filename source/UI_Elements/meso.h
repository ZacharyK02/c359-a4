/* GIMP RGBA C-Source image dump (meso.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 4 + 1];
} meso = {
  32, 32, 4,
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\031\031\031\377mll"
  "\377lll\377lll\377lll\377lll\377lll\377kkk\377\024\024\024\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\025\025\025\377kjl\377\210"
  "\210\206\377%\037\031\377\033\027\017\377\035\027\020\377\036\027\020\377\036\026\020\377"
  "\036\026\020\377\"\034\025\377\214\213\212\377klk\377\032\033\032\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\022\022\022\377mmn\377\216\217\213\377\033\031\027\377%\034\015\377"
  "\335\273+\377\344\302\036\377\347\303\035\377\351\306\036\377\355\312!\377\355"
  "\313\040\377\345\310/\377%\033\020\377\040\035\031\377\216\213\211\377lln\377\022"
  "\022\022\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\017\017\017\377\214\215\214\377\026\026\025\377\030\023\011\377\353\331\213"
  "\377\343\304\071\377\230t\010\377\226t\010\377\267\225\022\377\274\225\014\377"
  "\300\230\013\377\300\230\011\377\302\233\010\377\361\322\067\377\350\317E\377"
  "\"\032\007\377\032\025\016\377\217\217\213\377\027\027\026\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\023\023\023\377\214\214\213\377\031\032\026\377\364"
  "\361\324\377\355\337\222\377\222w\026\377\231s\011\377\326\257\023\377\331\261"
  "\012\377\333\262\010\377\332\257\013\377\333\262\007\377\333\262\006\377\333\262"
  "\011\377\320\245\012\377\315\246\016\377\361\327=\377\355\326\\\377!\034\023\377"
  "\210\207\207\377\021\021\021\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\027\027\027\377\205"
  "\206\206\377\031\031\026\377\363\360\323\377\361\342\227\377\177b\020\377\326"
  "\256\027\377\333\262\013\377\360\310\011\377\362\313\003\377\362\312\014\377\312"
  "\247\003\377\370\321\016\377\372\325\013\377\371\326\023\377\372\330#\377\370"
  "\330&\377\315\252\012\377\371\335>\377\351\333e\377\037\033\024\377\207\207\206"
  "\377\030\030\030\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\027\027\027\377\211\210\211\377\037\037\034\377\363\357"
  "\316\377\360\341\224\377\200c\017\377\324\256\027\377\362\310\012\377\363\311"
  "\007\377\362\312\005\377\361\311\010\377\335\263\003\377\316\244\002\377\335\262\010"
  "\377\371\324\015\377\373\330\023\377\372\332\037\377\371\333#\377\370\331,\377"
  "\313\253\017\377\370\340L\377\354\335i\377!\033\020\377\216\216\215\377\025\025"
  "\025\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377kkk\377\037\035\034\377\361\354\314\377\355\340\221\377\200d\020\377\323"
  "\256\031\377\354\306\007\377\360\310\007\377\362\312\004\377\361\311\007\377\334\264"
  "\005\377\332\265\025\377\354\301\021\377\273\215\002\377\330\262\012\377\373\327"
  "\027\377\373\331\"\377\371\334$\377\371\333.\377\370\331\071\377\335\271\040"
  "\377\370\342R\377\352\334g\377\034\032\027\377iii\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377jjj\377\033\027\024\377\354"
  "\333\216\377\225w\030\377\323\256\025\377\315\246\006\377\322\250\004\377\334\263"
  "\004\377\356\310\010\377\361\312\012\377\324\256\024\377\373\343t\377\337\266"
  "\021\377\325\247\007\377\263\211\005\377\370\325\032\377\371\330!\377\370\327&"
  "\377\315\251\011\377\264\220\012\377\372\336F\377\354\313\062\377\365\337b\377"
  "\027\024\020\377kkk\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\025\025\025\377\214\214\213\377#\035\023\377\350\323y\377\226s\024\377"
  "\331\261\017\377\317\247\004\377\360\310\"\377\312\244\006\377\276\225\003\377\355"
  "\306\017\377\327\254\006\377\346\300\025\377\334\261\004\377\324\251\006\377\255"
  "\204\003\377\365\323\034\377\322\260\007\377\315\246\004\377\327\256\017\377\255"
  "\205\004\377\371\340K\377\352\313\063\377\366\340c\377\037\035\022\377\214\214"
  "\214\377\024\024\024\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377`"
  "``\377\033\031\025\377\343\321}\377\224u\026\377\310\240\025\377\344\270\007\377"
  "\333\262\005\377\310\240\005\377\362\307$\377\333\261\007\377\315\245\003\377\325"
  "\252\020\377\335\263\003\377\334\261\002\377\331\260\006\377\276\230\003\377\314\245"
  "\007\377\371\324\061\377\332\260\015\377\252\203\003\377\350\303\031\377\373\341"
  "J\377\370\343Q\377\354\313\064\377\352\332r\377\037\035\031\377lmk\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377ddd\377\027\021\014\377\354\325"
  "p\377\225t\022\377\312\242\020\377\352\302\011\377\355\305\015\377\272\217\003"
  "\377\323\250\011\377\332\257\003\377\340\266\011\377\305\233\002\377\332\257\003"
  "\377\334\261\001\377\332\261\004\377\303\231\003\377\341\267\012\377\332\261\007\377"
  "\277\224\005\377\253\203\004\377\371\334\070\377\371\341N\377\372\344R\377\355"
  "\311\063\377\362\335e\377\033\027\020\377nmm\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377ddd\377\027\022\012\377\352\315+\377\272\224\025\377\313"
  "\243\020\377\351\301\013\377\356\310\005\377\352\305\016\377\267\216\001\377\333"
  "\261\011\377\334\262\001\377\333\257\004\377\333\260\003\377\334\261\002\377\333\261"
  "\003\377\333\260\006\377\333\260\002\377\306\233\006\377\254\202\003\377\352\301\020"
  "\377\372\336\071\377\371\342M\377\372\344R\377\354\311\063\377\361\335b\377"
  "\032\027\021\377mlo\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377__"
  "_\377\030\023\012\377\354\313!\377\273\225\020\377\314\242\020\377\350\300\011"
  "\377\357\306\011\377\354\306\015\377\317\250\016\377\367\320)\377\343\270\010"
  "\377\336\260\002\377\334\261\003\377\334\261\003\377\334\261\003\377\334\261\002\377"
  "\325\252\002\377\277\225\003\377\264\213\004\377\352\301\016\377\373\336\070\377"
  "\371\343L\377\371\345S\377\354\311\063\377\361\336e\377\032\030\020\377mln\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377aaa\377\027\021\011\377\335"
  "\272\030\377\273\225\022\377\314\242\020\377\347\276\013\377\353\303\015\377\322"
  "\251\007\377\365\315+\377\335\263\011\377\335\261\001\377\336\260\002\377\335\260"
  "\003\377\334\261\003\377\334\261\002\377\335\262\003\377\333\260\003\377\322\247\006"
  "\377\276\225\002\377\266\213\004\377\352\303\025\377\373\340E\377\371\344R\377"
  "\354\312\062\377\362\337m\377\032\027\021\377mlo\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377ijh\377\034\027\022\377\323\266(\377\275\225\023\377"
  "\312\243\020\377\343\274\021\377\317\246\013\377\365\316\060\377\332\262\014\377"
  "\332\260\011\377\332\256\005\377\335\260\002\377\335\260\002\377\335\260\004\377\334"
  "\260\002\377\334\261\005\377\333\257\011\377\324\253\005\377\320\244\006\377\275\223"
  "\004\377\265\213\003\377\352\304\032\377\374\342J\377\351\313\066\377\354\333x"
  "\377\037\035\030\377klj\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\027\027\026\377\216\214\213\377&\035\020\377\327\267\037\377\272\224\022\377\267"
  "\220\006\377\246{\003\377\246{\005\377\246|\002\377\245|\001\377\270\216\005\377\322"
  "\247\012\377\332\257\005\377\334\261\004\377\333\256\005\377\320\246\012\377\257"
  "\206\004\377\252\200\005\377\251\202\003\377\251\201\003\377\251\202\004\377\264\215"
  "\010\377\350\311\062\377\366\342{\377\"\034\023\377\214\213\214\377\030\030\027"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377kkl\377\036"
  "\026\023\377\331\267\037\377\274\227\014\377\335\264\016\377\351\276\014\377\351"
  "\301\012\377\350\301\014\377\322\251\013\377\261\210\003\377\253\201\003\377\303"
  "\227\007\377\334\260\012\377\264\211\011\377\252\202\002\377\254\203\005\377\352"
  "\302\020\377\370\326\"\377\370\330)\377\366\333\062\377\367\336C\377\347\313"
  "D\377\367\350\224\377\025\024\022\377mll\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377kkj\377!\034\030\377\323\266%\377\343"
  "\272\023\377\304\234\003\377\340\267\013\377\352\302\007\377\352\303\010\377\354"
  "\305\011\377\353\305\015\377\324\254\007\377\311\240\006\377\333\260\013\377\253"
  "\200\002\377\353\301\016\377\367\322\020\377\373\330\031\377\375\333\037\377\373"
  "\334$\377\373\333.\377\347\315K\377\375\371\301\377\356\343\222\377\035\032"
  "\026\377jjj\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\030\030\030\377\214\213\212\377&\037\030\377\326\270-\377\344\275\020"
  "\377\305\233\004\377\341\270\006\377\353\302\007\377\354\302\011\377\356\305\007\377"
  "\355\305\014\377\312\241\010\377\321\250\015\377\250\177\003\377\357\304\011\377"
  "\373\324\014\377\373\331\030\377\375\333!\377\373\332%\377\351\314=\377\374"
  "\371\307\377\354\342\230\377\035\032\020\377\211\212\211\377\024\024\024\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\032\032\031\377\215\214\211\377#\032\021\377\325\271.\377\345\276\021\377"
  "\321\245\005\377\341\266\010\377\343\271\005\377\352\301\011\377\354\304\016\377"
  "\272\221\002\377\253\201\004\377\254\202\003\377\356\304\011\377\372\325\010\377"
  "\373\330\031\377\373\330#\377\355\313\066\377\371\345|\377\360\352\273\377"
  "\035\032\030\377\213\213\211\377\024\024\024\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\""
  "\"!\377\221\221\217\377#\030\017\377\330\274\065\377\342\301%\377\317\245\010"
  "\377\336\263\014\377\343\270\005\377\354\304\010\377\362\313\017\377\366\320\020"
  "\377\366\321\022\377\371\323\011\377\371\325\017\377\356\312#\377\356\311/\377"
  "\365\337\\\377\355\336s\377\036\034\024\377\212\213\211\377\023\023\024\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377/\060.\377\215\214\213\377\033"
  "\026\020\377\037\021\007\377\334\272.\377\336\273&\377\337\264\014\377\337\264\017"
  "\377\337\263\017\377\337\265\023\377\357\311(\377\356\312)\377\356\313-\377"
  "\364\337W\377\352\332d\377\040\032\013\377\027\025\017\377\210\210\211\377\033\033"
  "\032\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\027\027\027\377nmp\377\231\231\230\377\035\032\026\377$\034\023\377\322\266+\377"
  "\341\301)\377\340\301.\377\344\310\071\377\356\325K\377\361\331Q\377\354\325"
  "\\\377\"\034\020\377!\036\033\377\215\213\212\377nmm\377\023\023\023\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\024\024\024\377llj\377\210\210\210\377\"\035\027\377\033\024\017"
  "\377\032\024\017\377\032\025\017\377\032\026\017\377\032\025\020\377!\034\027\377\213\213"
  "\213\377jji\377\030\030\030\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\027\027\027\377lkm\377lkn\377lkn\377lll\377mll\377nll\377"
  "kkk\377\027\027\026\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377",
};
