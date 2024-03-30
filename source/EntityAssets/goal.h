/* GIMP RGBA C-Source image dump (goal.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 4 + 1];
} goal = {
  32, 32, 4,
  "F\203Z\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377%G\060\377%G\060\377\026"
  ",\036\377\026,\036\377\026,\036\377\026,\036\377%G\060\377%G\060\377\026,\036\377\026"
  ",\036\377\064cC\377\026,\036\377\064cC\377\026,\036\377F\203Z\377F\203Z\377\026,"
  "\036\377\026,\036\377\026,\036\377\026,\036\377%G\060\377F\203Z\377F\203Z\377\026"
  ",\036\377\064cC\377%G\060\377%G\060\377F\203Z\377F\203Z\377\026,\036\377\026,\036"
  "\377\026,\036\377%G\060\377%G\060\377CLE\377v\230\177\377v\230\177\377[\213j"
  "\377\026,\036\377F\203Z\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377\026,\036"
  "\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377\026,\036\377\026,"
  "\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377%G\060\377%G\060\377F\203"
  "Z\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377F\203Z\377%G\060\377\026,"
  "\036\377p\205v\377\247\257\251\377\251\267\255\377w\231\201\377F\203Z\377"
  "%G\060\377F\203Z\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377F\203Z\377F"
  "\203Z\377%G\060\377%G\060\377\026,\036\377\026,\036\377%G\060\377\026,\036\377\026"
  ",\036\377F\203Z\377F\203Z\377%G\060\377F\203Z\377F\203Z\377%G\060\377F\203Z"
  "\377%G\060\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\177\220\203\377\276"
  "\300\276\377\275\276\275\377\202\240\213\377\064cC\377\026,\036\377%G\060\377"
  "\026,\036\377F\203Z\377F\203Z\377\026,\036\377F\203Z\377K`A\377c@+\377b@+\377"
  ":*\035\377F\203Z\377%G\060\377%G\060\377\026,\036\377\064cC\377F\203Z\377%G\060"
  "\377F\203Z\377\064cC\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377F\203Z\377"
  "F\203Z\377\026,\036\377y}z\377\276\300\276\377\276\300\276\377\177\220\203"
  "\377\064cC\377\026,\036\377\026,\036\377\026,\036\377\064cC\377F\203Z\377\026,\036"
  "\377\064cC\377e?*\377\230\034\022\377\231/\037\377pvQ\377F\203Z\377%G\060\377"
  "%G\060\377\026,\036\377\026,\036\377\064cC\377\026,\036\377\064cC\377%G\060\377F\203"
  "Z\377F\203Z\377\026,\036\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377lqn\377"
  "\253\256\254\377\266\255\254\377\231\201w\377\201\070\060\377\202C=\377sF@"
  "\377E\067-\377\071+\035\377fZ<\377e%\031\377Y%\031\377\200\064\"\377\262\035\021"
  "\377\270\024\016\377\235dF\377\212tQ\377~-#\377|xT\377]\177X\377F\203Z\377"
  "\026,\036\377\026,\036\377%G\060\377%G\060\377F\203Z\377%G\060\377\026,\036\377\026"
  ",\036\377\026,\036\377\064cC\377F\203Z\377QZV\377\203\204\204\377\246\205\204"
  "\377\300]Z\377\315HF\377\323uk\377\274\201q\377\200\203c\377d@+\377\230/"
  "\037\377\243\023\013\377\216\023\013\377\226\034\021\377\270\014\006\377\311&\034\377"
  "\314D\065\377\314\066/\377\312.+\377\262;/\377|xT\377F\203Z\377F\203Z\377\026"
  ",\036\377%G\060\377F\203Z\377\064cC\377%G\060\377%G\060\377\026,\036\377F\203Z\377"
  "\026,\036\377\064cC\377;HC\377efe\377\234ff\377\320II\377\351OO\377\357pp\377"
  "\333}u\377\252eV\377\232M\065\377\267\035\022\377\272\000\000\377\240\000\000\377\240"
  "\000\000\377\272\000\000\377\320\025\025\377\340((\377\347//\377\347//\377\313.+\377"
  "\201B\060\377\026,\036\377F\203Z\377F\203Z\377%G\060\377F\203Z\377\026,\036\377"
  "%G\060\377%G\060\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377:GB\377hvl\377"
  "\234dd\377\320HH\377\351OO\377\356pp\377\350qq\377\326SP\377\313\070-\377"
  "\310\020\016\377\272\000\000\377\240\000\000\377\237\000\000\377\272\000\000\377\320\025\025"
  "\377\340((\377\347//\377\347//\377\316O=\377\212tQ\377\026,\036\377\064cC\377"
  "F\203Z\377\026,\036\377\064cC\377\026,\036\377\026,\036\377%G\060\377F\203Z\377F"
  "\203Z\377%G\060\377%G\060\377@VJ\377jwm\377\234ff\377\320II\377\351OO\377\357"
  "pp\377\356qq\377\351OO\377\340((\377\320\021\021\377\272\000\000\377\240\000\000\377"
  "\240\000\000\377\272\000\000\377\320\025\025\377\340((\377\347//\377\347//\377\315"
  "P>\377\177-#\377\026,\036\377\026,\036\377\064cC\377\026,\036\377\026,\036\377\026"
  ",\036\377\026,\036\377F\203Z\377F\203Z\377%G\060\377\026,\036\377%G\060\377@VJ\377"
  "jwm\377\234ff\377\320II\377\351OO\377\357pp\377\356qq\377\351OO\377\340("
  "(\377\320\021\021\377\272\000\000\377\240\000\000\377\240\000\000\377\272\000\000\377\320\025"
  "\025\377\340((\377\347//\377\347//\377\313.+\377\177-#\377F\203Z\377\026,\036"
  "\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377F\203Z\377\064"
  "cC\377%G\060\377\026,\036\377\026,\036\377;HC\377fjg\377\235ff\377\320II\377\351"
  "OO\377\356pp\377\356qq\377\351OO\377\340((\377\320\021\021\377\272\000\000\377"
  "\237\000\000\377\240\000\000\377\272\000\000\377\320\025\025\377\340((\377\347//\377\347"
  "//\377\315P>\377\201B\060\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377F\203"
  "Z\377F\203Z\377\026,\036\377\064cC\377%G\060\377%G\060\377F\203Z\377F\203Z\377"
  "R\200b\377fjg\377\234ff\377\320II\377\351OO\377\357pp\377\356qq\377\351O"
  "O\377\340((\377\320\021\021\377\272\000\000\377\240\000\000\377\240\000\000\377\272\000\000"
  "\377\320\025\025\377\340((\377\347//\377\347//\377\315P>\377\177-#\377F\203"
  "Z\377F\203Z\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377%G\060"
  "\377%G\060\377F\203Z\377F\203Z\377F\203Z\377\066C>\377[]\\\377\213^]\377\271"
  "VL\377\326ON\377\351us\377\356qq\377\351OO\377\337((\377\320\021\021\377\271"
  "\037\022\377\227:&\377\217E-\377\243\023\013\377\266\035\030\377\305\062*\377\324"
  "\064/\377\341\070\063\377\316O=\377\201-#\377%G\060\377F\203Z\377F\203Z\377\026"
  ",\036\377F\203Z\377F\203Z\377F\203Z\377%G\060\377F\203Z\377F\203Z\377\026,\036"
  "\377\026,\036\377,\071\062\377GIH\377]HF\377v\071\064\377\250XO\377\333}u\377\356"
  "qq\377\351OO\377\337((\377\320\021\021\377\262\035\021\377\205cC\377grN\377r"
  "sN\377p'\034\377}A.\377\252gJ\377\324I:\377\313.+\377\203B\060\377%G\060\377"
  "\064cC\377F\203Z\377\026,\036\377\026,\036\377\064cC\377F\203Z\377%G\060\377F\203"
  "Z\377\064cC\377%G\060\377F\203Z\377.E\065\377\070;\070\377=WG\377.E\065\377vVI"
  "\377\272ti\377\321he\377\316MI\377\304)&\377\266\033\025\377\230\034\022\377"
  "c@+\377%G\060\377F\203Z\377F\203Z\377%G\060\377~xS\377\263L\071\377\262;/\377"
  "tC\060\377\026,\036\377\026,\036\377\064cC\377%G\060\377\026,\036\377\026,\036\377\064"
  "cC\377\026,\036\377\064cC\377%G\060\377F\203Z\377F\203Z\377%\062)\377\067:\070\377"
  "=WG\377@vT\377KM:\377sF@\377\205TH\377\203I:\377\206sP\377~rO\377owQ\377"
  ":+\035\377%G\060\377\064cC\377F\203Z\377\026,\036\377QaB\377n-\"\377rC\060\377"
  "MF\060\377\026,\036\377\026,\036\377%G\060\377%G\060\377\026,\036\377F\203Z\377\026"
  ",\036\377\026,\036\377%G\060\377%G\060\377F\203Z\377F\203Z\377&\062*\377\070;\070"
  "\377AWG\377DuT\377\026,\036\377%G\060\377%G\060\377F\203Z\377F\203Z\377F\203"
  "Z\377\026,\036\377\026,\036\377%G\060\377%G\060\377\064cC\377\026,\036\377\026,\036"
  "\377\026,\036\377%G\060\377\026,\036\377%G\060\377\026,\036\377\026,\036\377F\203Z"
  "\377F\203Z\377F\203Z\377F\203Z\377\026,\036\377%G\060\377F\203Z\377F\203Z\377"
  "\026,\036\377.E\065\377\070;\070\377:A<\377DuT\377F\203Z\377%G\060\377F\203Z\377"
  "F\203Z\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377%G\060\377"
  "%G\060\377\026,\036\377F\203Z\377F\203Z\377F\203Z\377%G\060\377%G\060\377F\203"
  "Z\377\026,\036\377%G\060\377F\203Z\377%G\060\377F\203Z\377F\203Z\377%G\060\377"
  "F\203Z\377\064cC\377\026,\036\377.E\065\377:A<\377\070;\070\377\067[B\377F\203Z"
  "\377%G\060\377F\203Z\377\064cC\377%G\060\377F\203Z\377%G\060\377\026,\036\377\026"
  ",\036\377%G\060\377%G\060\377F\203Z\377F\203Z\377F\203Z\377\064cC\377\064cC\377"
  "%G\060\377F\203Z\377F\203Z\377\026,\036\377%G\060\377%G\060\377\064cC\377F\203"
  "Z\377\026,\036\377\064cC\377\026,\036\377\026,\036\377.E\065\377:A<\377\070;\070\377"
  "&\062*\377\064cC\377\026,\036\377\064cC\377%G\060\377F\203Z\377F\203Z\377\026,\036"
  "\377\026,\036\377F\203Z\377\026,\036\377%G\060\377\064cC\377F\203Z\377\026,\036\377"
  "%G\060\377\064cC\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377%"
  "G\060\377%G\060\377\064cC\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377&\062"
  "*\377AWG\377AWG\377DuT\377\026,\036\377\026,\036\377%G\060\377%G\060\377F\203Z"
  "\377F\203Z\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\064cC"
  "\377\064cC\377\026,\036\377%G\060\377%G\060\377\026,\036\377\026,\036\377F\203Z\377"
  "F\203Z\377\026,\036\377\026,\036\377%G\060\377%G\060\377\026,\036\377F\203Z\377F"
  "\203Z\377F\203Z\377.E\065\377:A<\377AWG\377DuT\377F\203Z\377\026,\036\377%G"
  "\060\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377\026,\036\377F\203Z\377F\203"
  "Z\377\026,\036\377%G\060\377\064cC\377\026,\036\377%G\060\377\026,\036\377\026,\036"
  "\377\026,\036\377\064cC\377F\203Z\377\026,\036\377\026,\036\377%G\060\377%G\060\377"
  "F\203Z\377F\203Z\377F\203Z\377\064cC\377\066ZA\377\066>\070\377\066>\070\377$\061"
  "(\377F\203Z\377F\203Z\377%G\060\377F\203Z\377\064cC\377\026,\036\377\026,\036\377"
  "F\203Z\377\026,\036\377F\203Z\377F\203Z\377%G\060\377\026,\036\377\026,\036\377"
  "F\203Z\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377\064cC\377\026,\036\377"
  "F\203Z\377\026,\036\377%G\060\377\064cC\377F\203Z\377\026,\036\377%G\060\377\064"
  "Y?\377.\062/\377.\062/\377!.%\377\064cC\377F\203Z\377\026,\036\377\064cC\377\026"
  ",\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\064cC\377F\203Z\377\026"
  ",\036\377\026,\036\377F\203Z\377F\203Z\377F\203Z\377%G\060\377\026,\036\377\026"
  ",\036\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\064cC\377\064"
  "cC\377\026,\036\377%G\060\377(A\060\377*.+\377*.+\377\037-#\377\026,\036\377\064"
  "cC\377\026,\036\377%G\060\377%G\060\377\026,\036\377F\203Z\377F\203Z\377\026,\036"
  "\377%G\060\377\064cC\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377"
  "F\203Z\377%G\060\377%G\060\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377\026"
  ",\036\377\026,\036\377\064cC\377\026,\036\377%G\060\377\037-#\377*.+\377*.+\377\037"
  "-#\377F\203Z\377\026,\036\377\026,\036\377%G\060\377%G\060\377F\203Z\377F\203Z"
  "\377%G\060\377\026,\036\377%G\060\377%G\060\377\026,\036\377F\203Z\377\064cC\377"
  "\026,\036\377F\203Z\377F\203Z\377\026,\036\377%G\060\377%G\060\377\026,\036\377\026"
  ",\036\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377\026,\036\377F\203Z\377A"
  "sQ\377\066O=\377*.+\377AsQ\377F\203Z\377\026,\036\377F\203Z\377\026,\036\377%"
  "G\060\377F\203Z\377\064cC\377%G\060\377\026,\036\377%G\060\377\026,\036\377\026,\036"
  "\377\064cC\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377%G\060\377"
  "%G\060\377F\203Z\377\026,\036\377\064cC\377F\203Z\377\026,\036\377\026,\036\377F"
  "\203Z\377F\203Z\377AtQ\377*.+\377*.+\377AtQ\377F\203Z\377\026,\036\377F\203"
  "Z\377F\203Z\377\026,\036\377\064cC\377%G\060\377%G\060\377F\203Z\377F\203Z\377"
  "F\203Z\377\026,\036\377%G\060\377%G\060\377F\203Z\377F\203Z\377%G\060\377\026,"
  "\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377\064cC\377\026"
  ",\036\377F\203Z\377F\203Z\377\026,\036\377'C\060\377&.(\377;aF\377BxS\377\026"
  ",\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377%G\060\377%G\060\377F\203"
  "Z\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377%G\060\377%G\060\377F\203Z\377"
  "\064cC\377%G\060\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377\026,\036\377\026"
  ",\036\377\026,\036\377\026,\036\377F\203Z\377\064cC\377%G\060\377&F\060\377\035-\""
  "\377BxT\377\064`B\377%G\060\377\026,\036\377\026,\036\377F\203Z\377F\203Z\377%"
  "G\060\377F\203Z\377F\203Z\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377"
  "\026,\036\377%G\060\377\064cC\377\026,\036\377%G\060\377\026,\036\377F\203Z\377F\203"
  "Z\377%G\060\377\026,\036\377\026,\036\377\026,\036\377\026,\036\377\064cC\377\026,\036"
  "\377%G\060\377%G\060\377\026,\036\377\064cC\377\026,\036\377%G\060\377%G\060\377\026"
  ",\036\377\064cC\377F\203Z\377%G\060\377F\203Z\377\064cC\377%G\060\377F\203Z\377"
  "%G\060\377\026,\036\377\026,\036\377%G\060\377%G\060\377F\203Z\377\026,\036\377\026"
  ",\036\377F\203Z\377\064cC\377%G\060\377",
};
