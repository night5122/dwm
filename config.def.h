/*
            _   ___       __    __  
           / | / (_)___ _/ /_  / /_    
	  /  |/ / / __ `/ __ \/ __/   
	 / /|  / / /_/ / / / / /_     
	/_/ |_/_/\__, /_/ /_/\__/  
	        /____/    
	Desktop Window Manager (6.2.1)       
*/

static const unsigned int borderpx    = 0;        
static const unsigned int gappx       = 32;       
static const unsigned int snap        = 32;       
static const int showbar              = 1; 
static const int topbar               = 1; 
static const char *fonts[]            = { "Source Sans Pro:size=10", "JetBrains Mono Nerd Font:size=12" };
static const char dmenufont[]         = { "Source Sans Pro:size=10" };
static const char col_1[]             = "#282c34"; 
static const char col_2[]             = "#282c34"; 
static const char col_3[]             = "#d7d7d7";
static const char col_4[]             = "#282c34"; 
static const unsigned int baralpha    = 0xa0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]        = {[SchemeNorm]={col_3,col_1,col_2},[SchemeSel]={ col_3,col_4,col_4},};
static const unsigned int alphas[][3] = {[SchemeNorm]={OPAQUE,baralpha,borderalpha},[SchemeSel]={OPAQUE,baralpha,borderalpha },};
static const char *tags[]             = {"","","","",""}; 
static const Rule rules[]             = {NULL};
static const float mfact              = 0.55; 
static const int nmaster              = 1;    
static const int resizehints          = 1;    
static const Layout layouts[]         = {{"     Tiling",tile },};

/*
 
	Key Definition(s)
 
*/

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/*
 
	Command(s)
 
*/

static char dmenumon[2]               = "0"; 
static const char *dmenucmd[]         = {"dmenu_run","-m", dmenumon,"-fn", dmenufont,"-nb",col_1,"-nf",col_3,"-sb", col_4,"-sf",col_4,NULL};
static const char *termcmd[]          = {"st",NULL};

/*

	Key Bind(s)

*/

static Key keys[] = {
	{ MODKEY,                       XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/*
 
	Mouse Bind(s)
 
*/

static Button buttons[] = {
	{ ClkLtSymbol,                  0,         Button1,        setlayout,      {0} },
	{ ClkLtSymbol,                  0,         Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,                  0,         Button2,        zoom,           {0} },
	{ ClkStatusText,                0,         Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,                 MODKEY,    Button1,        movemouse,      {0} },
	{ ClkClientWin,                 MODKEY,    Button2,        togglefloating, {0} },
	{ ClkClientWin,                 MODKEY,    Button3,        resizemouse,    {0} },
	{ ClkTagBar,                    0,         Button1,        view,           {0} },
	{ ClkTagBar,                    0,         Button3,        toggleview,     {0} },
	{ ClkTagBar,                    MODKEY,    Button1,        tag,            {0} },
	{ ClkTagBar,                    MODKEY,    Button3,        toggletag,      {0} },
};
