#ifndef TZ_CONFIG
#define TZ_CONFIG

#include "config.h"
#include <errno.h>
#include <glib.h>

#ifndef __sun
#  define TZ_DATA_FILE "/usr/share/zoneinfo/zone.tab"
#else
#  define TZ_DATA_FILE "/usr/share/lib/zoneinfo/tab/zone_sun.tab"
#endif

typedef struct _TzDB TzDB;
typedef struct _TzLocation TzLocation;
typedef struct _TzInfo TzInfo;


struct _TzDB
{
        GPtrArray  *locations;
        GHashTable *backward;
};

struct _TzLocation
{
        gchar *country;
        gdouble latitude;
        gdouble longitude;
        gchar *zone;
        gchar *comment;

        gdouble dist; /* distance to clicked point for comparison */
};

/* see the glibc info page information on time zone information */
/*  tzname_normal    is the default name for the timezone */
/*  tzname_daylight  is the name of the zone when in daylight savings */
/*  utc_offset       is offset in seconds from utc */
/*  daylight         if non-zero then location obeys daylight savings */

struct _TzInfo
{
        gchar *tzname_normal;
        gchar *tzname_daylight;
        glong utc_offset;
        gint daylight;
};

typedef struct
{
    gdouble offset;
    guchar red;
    guchar green;
    guchar blue;
    guchar alpha;
} CcTimezoneMapOffset;

static CcTimezoneMapOffset color_codes[] =
{
    {-11.0, 43, 0, 0, 255 },
    {-10.0, 85, 0, 0, 255 },
    {-9.5, 102, 255, 0, 255 },
    {-9.0, 128, 0, 0, 255 },
    {-8.0, 170, 0, 0, 255 },
    {-7.0, 212, 0, 0, 255 },
    {-6.0, 255, 0, 1, 255 }, // north
    {-6.0, 255, 0, 0, 255 }, // south
    {-5.0, 255, 42, 42, 255 },
    {-4.5, 192, 255, 0, 255 },
    {-4.0, 255, 85, 85, 255 },
    {-3.5, 0, 255, 0, 255 },
    {-3.0, 255, 128, 128, 255 },
    {-2.0, 255, 170, 170, 255 },
    {-1.0, 255, 213, 213, 255 },
    {0.0, 43, 17, 0, 255 },
    {1.0, 85, 34, 0, 255 },
    {2.0, 128, 51, 0, 255 },
    {3.0, 170, 68, 0, 255 },
    {3.5, 0, 255, 102, 255 },
    {4.0, 212, 85, 0, 255 },
    {4.5, 0, 204, 255, 255 },
    {5.0, 255, 102, 0, 255 },
    {5.5, 0, 102, 255, 255 },
    {5.75, 0, 238, 207, 247 },
    {6.0, 255, 127, 42, 255 },
    {6.5, 204, 0, 254, 254 },
    {7.0, 255, 153, 85, 255 },
    {8.0, 255, 179, 128, 255 },
    {9.0, 255, 204, 170, 255 },
    {9.5, 170, 0, 68, 250 },
    {10.0, 255, 230, 213, 255 },
    {10.5, 212, 124, 21, 250 },
    {11.0, 212, 170, 0, 255 },
    {11.5, 249, 25, 87, 253 },
    {12.0, 255, 204, 0, 255 },
    {12.75, 254, 74, 100, 248 },
    {13.0, 255, 85, 153, 250 },
    {-100, 0, 0, 0, 0 }
};


TzDB      *tz_load_db                 (void);
void       tz_db_free                 (TzDB *db);
char *     tz_info_get_clean_name     (TzDB *tz_db,
                                       const char *tz);
GPtrArray *tz_get_locations           (TzDB *db);
void       tz_location_get_position   (TzLocation *loc,
                                       double *longitude, double *latitude);
char      *tz_location_get_country    (TzLocation *loc);
gchar     *tz_location_get_zone       (TzLocation *loc);
gchar     *tz_location_get_comment    (TzLocation *loc);
glong      tz_location_get_utc_offset (TzLocation *loc);
gint       tz_location_set_locally    (TzLocation *loc);
TzInfo    *tz_info_from_location      (TzLocation *loc);
void       tz_info_free               (TzInfo *tz_info);

extern  gdouble
convert_longtitude_to_x (gdouble longitude, gint map_width);
extern gdouble
convert_latitude_to_y (gdouble latitude, gdouble map_height);

extern gint
sort_locations (TzLocation *a,
                TzLocation *b);

#endif

