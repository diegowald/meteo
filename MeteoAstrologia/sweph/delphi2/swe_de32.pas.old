
{Swiss Ephemeris function declarations for Delphi 2 (32-bit)

 ATTENTION: there may be errors in some less important function
 declarations, because we have not tested all of them.
 If a function does not work, you can try to correct it comparing
 it with the C-declaration in swedll.h. This should be rather simple 
 from the given samples. Please, inform Astrodienst about errors.
}

function swe_calc(tjd          : double;    {Julian day number}
                   ipl         : Integer;   {planet number}
                   iflag       : Longint;   {flag bits}
                   var xx      : double;    {first of 6 doubles}
                   sErr        : PChar      {Error-String}
): Longint; stdcall; far; external 'swedll32.dll' name '_swe_calc@24';

procedure swe_close; stdcall; far; external 'swedll32.dll' name '_swe_close@0';

procedure swe_cotrans(var xpin  : double;
                   var xpout    : double;
                   eps          : double
); stdcall; far; external 'swedll32.dll' name '_swe_cotrans@16';

procedure swe_cotrans_sp(var xpin  : double;
                   var xpout    : double;
                   eps          : double
); stdcall; far; external 'swedll32.dll' name '_swe_cotrans_sp@16';

function swe_csnorm(p: Longint
): Longint; stdcall; far; external 'swedll32.dll' name '_swe_csnorm@4';

function swe_csroundsec(x: Longint
): Longint; stdcall; far; external 'swedll32.dll' name '_swe_csroundsec@4';

function swe_cs2degstr(t: Longint;
                   s     : pchar
): pchar; stdcall; far; external 'swedll32.dll' name '_swe_cs2degstr@8';

function swe_cs2lonlatstr(t: Longint;
                   pch   : char;
                   mch   : char;
                   s     : pchar
): pchar; stdcall; far; external 'swedll32.dll' name '_swe_cs2lonlatstr_d@16';

function swe_cs2timestr(t: Longint;
                   sep   : integer;
                   suppresszero : integer;
                   s     : pchar
): pchar; stdcall; far; external 'swedll32.dll' name '_swe_cs2timestr@16';

function swe_date_conversion(year: integer;
                   month       : integer;
                   day         : integer;
                   utime       : double;
                   c           : char;      {'g'regorian or 'j'ulian}
                   var tjd     : double
): integer; stdcall; far; external 'swedll32.dll' name '_swe_date_conversion@28';

function swe_day_of_week(var tjd: double
): integer; stdcall; far; external 'swedll32.dll' name '_swe_day_of_week@8';

function swe_degnorm(x: double
): double; stdcall; far; external 'swedll32.dll' name '_swe_degnorm@8';

function swe_deltat(tjd  : double                   
): double; stdcall; far; external 'swedll32.dll' name '_swe_deltat@8';

function swe_difcsn(p1: Longint;
                   p2 : Longint
): Longint; stdcall; far; external 'swedll32.dll' name '_swe_difcsn@8';

function swe_difcs2n(p1: Longint;
                   p2 : Longint
): Longint; stdcall; far; external 'swedll32.dll' name '_swe_difcs2n@8';

function swe_difdegn(p1 : double;
                   p2     : double
): double; stdcall; far; external 'swedll32.dll' name '_swe_difdegn@16';

function swe_difdeg2n(p1 : double;
                   p2     : double                   
): double; stdcall; far; external 'swedll32.dll' name '_swe_difdeg2n@16';

function swe_d2l(x: double
): Longint; stdcall; far; external 'swedll32.dll' name '_swe_d2l@8';

function swe_fixstar(star      : pchar;     {star name}
                   tjd         : double;    {Julian day number}
                   iflag       : Longint;   {flag bits}
                   var xx      : double;    {first of 6 doubles}
                   sErr        : pchar      {Error-String}
): Longint; stdcall; far; external 'swedll32.dll' name '_swe_fixstar@24';

function swe_get_planet_name(ipl : integer;
                   pname      : PChar
) : PChar; stdcall; far; external 'swedll32.dll' name '_swe_get_planet_name@8';

function swe_get_tid_acc(t_acc: double
) : double; stdcall; far; external 'swedll32.dll' name '_swe_get_tid_acc@0';

function swe_houses(tjdut      : double;
                    geolat     : double;
                    geolon     : double;
                    hsys       : char;
                    var hcusp0 : double;
                    var ascmc0 : double
) : integer; stdcall; far; external 'swedll32.dll' name '_swe_houses@36';

function swe_houses_armc(armc  : double;
                    geolat     : double;
                    eps        : double;
                    hsys       : char;
                    var hcusp0 : double;
                    var ascmc0 : double
) : integer; stdcall; far; external 'swedll32.dll' name '_swe_houses_armc@36';

function swe_house_pos(armc: double;
                    geolon : double;
                    eps    : double;
                    hsys       : char;
                    var xpin   : double;  {2 doubles: ecl. longitude and latitude}
                    serr       : pchar
): double; stdcall; far; external 'swedll32.dll' name '_swe_house_pos@36';

function swe_julday(year     : integer;
                    month      : integer;
                    day        : integer;
                    hour       : double;
                    gregflag   : integer
) : double; stdcall; far; external 'swedll32.dll' name '_swe_julday@24';

procedure swe_revjul(tjd        : double;
                    gregflag    : integer;
                    var year    : integer;
                    var month   : integer;
                    var day     : integer;
                    var hour    : double
); stdcall; far; external 'swedll32.dll' name '_swe_revjul@28';

procedure swe_set_ephe_path(path: pchar
); stdcall; far; external 'swedll32.dll' name '_swe_set_ephe_path@4';

procedure swe_set_jpl_file(fname: pchar
); stdcall; far; external 'swedll32.dll' name '_swe_set_jpl_file@4';

procedure swe_set_tid_acc(t_acc: double
); stdcall; far; external 'swedll32.dll' name '_swe_set_tid_acc@8';

procedure swe_set_topo(geolon   : double;
                   geolat       : double;
                   height       : double
); stdcall; far; external 'swedll32.dll' name '_swe_set_topo@24';

function swe_sidtime(tjdut: double                    
) : double; stdcall; far; external 'swedll32.dll' name '_swe_sidtime@8';

function swe_sidtime0(tjdut: double;
                    eps_true: double;
                    nut_long: double                    
) : Integer; stdcall; far; external 'swedll32.dll' name '_swe_sidtime0@24';



{ Swiss Ephemeris constants for Pascal }
CONST

SE_ECL_NUT : integer =      -1;

SE_SUN : integer =          0;       
SE_MOON : integer =         1;       
SE_MERCURY : integer =      2;      
SE_VENUS : integer =        3;      
SE_MARS : integer =         4;      
SE_JUPITER : integer =      5;      
SE_SATURN : integer =       6;      
SE_URANUS : integer =       7;      
SE_NEPTUNE : integer =      8;      
SE_PLUTO : integer =        9;      
SE_MEAN_NODE : integer =    10;     
SE_TRUE_NODE : integer =    11;
SE_MEAN_APOG : integer =    12;      
SE_OSCU_APOG : integer =    13;    
SE_EARTH : integer =        14;      
SE_CHIRON : integer =       15;     
SE_PHOLUS : integer =       16;     
SE_CERES : integer =        17;     
SE_PALLAS : integer =       18;     
SE_JUNO : integer =         19;     
SE_VESTA : integer =        20;     

SE_NPLANETS : integer =     21;     

SE_AST_OFFSET : integer =   10000;
SE_FICT_OFFSET : integer =  40;
SE_NFICT_ELEM : integer =   15;

{ Hamburger or Uranian "planets" }
SE_CUPIDO : integer =       	40;
SE_HADES : integer =        	41;
SE_ZEUS : integer =         	42;
SE_KRONOS : integer =       	43;
SE_APOLLON : integer =      	44;
SE_ADMETOS : integer =      	45;
SE_VULKANUS : integer =     	46;
SE_POSEIDON : integer =     	47;
{ other ficticious bodies }
SE_ISIS : integer =         	48;
SE_NIBIRU : integer =       	49;
SE_HARRINGTON : integer =           50;
SE_NEPTUNE_LEVERRIER : integer =    51;
SE_NEPTUNE_ADAMS : integer =        52;
SE_PLUTO_LOWELL : integer =         53;
SE_PLUTO_PICKERING : integer =      54;

{
  flag bits for parameter iflag in function swe_calc()
  The flag bits are defined in such a way that iflag = 0 delivers what one
  usually wants:
     - the default ephemeris (SWISS) is used,
     - apparent geocentric positions referring to the true equinox of date are returned.
  If not only coordinates, but also speed values are required, use iflag = SEFLG_SPEED.
 }
SEFLG_JPLEPH : Longint =    	1;       { use JPL ephemeris }
SEFLG_SWIEPH : Longint =    	2;       { use SWISSEPH ephemeris }
SEFLG_MOSEPH : Longint =    	4;       { use Moshier ephemeris }
SEFLG_HELCTR : Longint =        8;      { return heliocentric position }
SEFLG_TRUEPOS : Longint =       16;    { return true positions, not apparent }
SEFLG_J2000 : Longint =         32;    { no precession, i.e. give J2000 equinox }
SEFLG_NONUT : Longint =         64;    { no nutation, i.e. mean equinox of date }
SEFLG_SPEED : Longint =         256;    { high precision speed (analytical computation) }
SEFLG_NOGDEFL : Longint =       512;    { turn off gravitational deflection }
SEFLG_NOABERR : Longint =       1024;   { turn off 'annual' aberration of light }
SEFLG_EQUATORIAL : Longint =    (2*1024);   { equatorial positions are wanted }
SEFLG_XYZ : Longint =           (4*1024);   { cartesian, not polar, coordinates are wanted}
SEFLG_RADIANS : Longint =       (8*1024);   { coordinates are wanted in radians, not degrees }
SEFLG_BARYCTR : Longint =       (16*1024);  { barycentric positions }
SEFLG_TOPOCTR : Longint =       (32*1024);  { topocentric positions }

SE_MAX_STNAME : Longint =	20;	{ maximum size of fixstar name;
                                          the parameter star in swe_fixstar
					  must allow twice this space for
				          the returned star name.
					 }
