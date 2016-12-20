/*
    Copyright (C) 2016 Jolla Ltd.
    Contact: Chris Adams <chris.adams@jollamobile.com>

    This file is part of geoclue-mlsdb.

    Geoclue-mlsdb is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License.
*/

#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QSet>
#include <QVariant>
#include <QDataStream>
#include <QFile>
#include <QDir>

#include <stdio.h>
#include <stdlib.h>

#define USE_CONCURRENT 0
#if USE_CONCURRENT
#define USE_STD_CONCURRENT 1
#define THREADCOUNT 3
#if USE_STD_CONCURRENT
#include <thread>
#include <future>
#else
#include <qtconcurrentrun.h>
#endif
#endif

#include "mlsdbserialisation.h"

struct BoundingBox {
    // usually zero, except in cases where the country crosses meridian or pole
    double latShift;
    double lonShift;

    // bounding box lower-left/upper-right corners
    // note that these are post-shift values!
    MlsdbCoords lowerLeft;
    MlsdbCoords upperRight;

    bool contains(const MlsdbCoords &c) const {
        if (Q_UNLIKELY(latShift != 0.0 || lonShift != 0.0)) {
            return (c.lat+latShift) >= lowerLeft.lat && (c.lat+latShift) <= upperRight.lat
                && (c.lon+lonShift) >= lowerLeft.lon && (c.lon+lonShift) <= upperRight.lon;
        }

        return c.lat >= lowerLeft.lat && c.lat <= upperRight.lat
            && c.lon >= lowerLeft.lon && c.lon <= upperRight.lon;
    }
};
Q_DECLARE_TYPEINFO(BoundingBox, Q_PRIMITIVE_TYPE);

QDataStream &operator<<(QDataStream &out, const BoundingBox &bbox)
{
    out << bbox.latShift << bbox.lonShift << bbox.lowerLeft << bbox.upperRight;
    return out;
}

QDataStream &operator>>(QDataStream &in, BoundingBox &bbox)
{
    in >> bbox.latShift >> bbox.lonShift >> bbox.lowerLeft >> bbox.upperRight;
    return in;
}

// These are approximate only!
QMap<QString, BoundingBox> countryBoundingBoxes()
{
    QMap<QString, BoundingBox> retn;

// Africa

    BoundingBox algeria_bb;
    algeria_bb.latShift = 0.0;
    algeria_bb.lonShift = 0.0;
    algeria_bb.lowerLeft.lat = 19.057;
    algeria_bb.lowerLeft.lon = -8.684;
    algeria_bb.upperRight.lat = 37.118;
    algeria_bb.upperRight.lon = 11.999;
    retn.insert(QLatin1String("Algeria"), algeria_bb);

    BoundingBox angola_bb;
    angola_bb.latShift = 0.0;
    angola_bb.lonShift = 0.0;
    angola_bb.lowerLeft.lat = -17.931;
    angola_bb.lowerLeft.lon = 11.6400;
    angola_bb.upperRight.lat = -4.438;
    angola_bb.upperRight.lon = 24.080;
    retn.insert(QLatin1String("Angola"), angola_bb);

    BoundingBox benin_bb;
    benin_bb.latShift = 0.0;
    benin_bb.lonShift = 0.0;
    benin_bb.lowerLeft.lat = 6.142;
    benin_bb.lowerLeft.lon = 0.772;
    benin_bb.upperRight.lat = 12.236;
    benin_bb.upperRight.lon = 3.797;
    retn.insert(QLatin1String("Benin"), benin_bb);

    BoundingBox botswana_bb;
    botswana_bb.latShift = 0.0;
    botswana_bb.lonShift = 0.0;
    botswana_bb.lowerLeft.lat = -26.828;
    botswana_bb.lowerLeft.lon = 19.895;
    botswana_bb.upperRight.lat = -17.661;
    botswana_bb.upperRight.lon = 29.432;
    retn.insert(QLatin1String("Botswana"), botswana_bb);

    BoundingBox burkina_faso_bb;
    burkina_faso_bb.latShift = 0.0;
    burkina_faso_bb.lonShift = 0.0;
    burkina_faso_bb.lowerLeft.lat = 9.611;
    burkina_faso_bb.lowerLeft.lon = -5.471;
    burkina_faso_bb.upperRight.lat = 15.116;
    burkina_faso_bb.upperRight.lon = 2.177;
    retn.insert(QLatin1String("Burkina_Faso"), burkina_faso_bb);

    BoundingBox burundi_bb;
    burundi_bb.latShift = 0.0;
    burundi_bb.lonShift = 0.0;
    burundi_bb.lowerLeft.lat = -4.499;
    burundi_bb.lowerLeft.lon = 29.025;
    burundi_bb.upperRight.lat = -2.348;
    burundi_bb.upperRight.lon = 30.752;
    retn.insert(QLatin1String("Burundi"), burundi_bb);

    BoundingBox cameroon_bb;
    cameroon_bb.latShift = 0.0;
    cameroon_bb.lonShift = 0.0;
    cameroon_bb.lowerLeft.lat = 1.728;
    cameroon_bb.lowerLeft.lon = 8.488;
    cameroon_bb.upperRight.lat = 12.859;
    cameroon_bb.upperRight.lon = 16.013;
    retn.insert(QLatin1String("Cameroon"), cameroon_bb);

    BoundingBox canary_islands_bb;
    canary_islands_bb.latShift = 0.0;
    canary_islands_bb.lonShift = 0.0;
    canary_islands_bb.lowerLeft.lat = 27.637;
    canary_islands_bb.lowerLeft.lon = -18.161;
    canary_islands_bb.upperRight.lat = 29.415;
    canary_islands_bb.upperRight.lon = -13.419;
    retn.insert(QLatin1String("Canary_Islands"), canary_islands_bb);

    BoundingBox cape_verde_bb;
    cape_verde_bb.latShift = 0.0;
    cape_verde_bb.lonShift = 0.0;
    cape_verde_bb.lowerLeft.lat = 14.802;
    cape_verde_bb.lowerLeft.lon = -25.359;
    cape_verde_bb.upperRight.lat = 17.197;
    cape_verde_bb.upperRight.lon = -22.666;
    retn.insert(QLatin1String("Cape_Verde"), cape_verde_bb);

    BoundingBox central_african_republic_bb;
    central_african_republic_bb.latShift = 0.0;
    central_african_republic_bb.lonShift = 0.0;
    central_african_republic_bb.lowerLeft.lat = 2.267;
    central_african_republic_bb.lowerLeft.lon = 14.459;
    central_african_republic_bb.upperRight.lat = 11.142;
    central_african_republic_bb.upperRight.lon = 27.374;
    retn.insert(QLatin1String("Central_African_Republic"), central_african_republic_bb);

    BoundingBox ceuta_bb;
    ceuta_bb.latShift = 0.0;
    ceuta_bb.lonShift = 0.0;
    ceuta_bb.lowerLeft.lat = 35.871;
    ceuta_bb.lowerLeft.lon = -5.353;
    ceuta_bb.upperRight.lat = 35.907;
    ceuta_bb.upperRight.lon = -5.278;
    retn.insert(QLatin1String("Ceuta"), ceuta_bb);

    BoundingBox chad_bb;
    chad_bb.latShift = 0.0;
    chad_bb.lonShift = 0.0;
    chad_bb.lowerLeft.lat = 7.422;
    chad_bb.lowerLeft.lon = 13.540;
    chad_bb.upperRight.lat = 23.410;
    chad_bb.upperRight.lon = 23.889;
    retn.insert(QLatin1String("Chad"), chad_bb);

    BoundingBox comoros_bb;
    comoros_bb.latShift = 0.0;
    comoros_bb.lonShift = 0.0;
    comoros_bb.lowerLeft.lat = -12.414;
    comoros_bb.lowerLeft.lon = 43.216;
    comoros_bb.upperRight.lat = -11.362;
    comoros_bb.upperRight.lon = 44.538;
    retn.insert(QLatin1String("Comoros"), comoros_bb);

    BoundingBox congo_bb;
    congo_bb.latShift = 0.0;
    congo_bb.lonShift = 0.0;
    congo_bb.lowerLeft.lat = -5.038;
    congo_bb.lowerLeft.lon = 11.093;
    congo_bb.upperRight.lat = 3.728;
    congo_bb.upperRight.lon = 18.453;
    retn.insert(QLatin1String("Congo"), congo_bb);

    BoundingBox democratic_republic_of_the_congo_bb;
    democratic_republic_of_the_congo_bb.latShift = 0.0;
    democratic_republic_of_the_congo_bb.lonShift = 0.0;
    democratic_republic_of_the_congo_bb.lowerLeft.lat = -13.257;
    democratic_republic_of_the_congo_bb.lowerLeft.lon = 12.182;
    democratic_republic_of_the_congo_bb.upperRight.lat = 5.256;
    democratic_republic_of_the_congo_bb.upperRight.lon = 31.174;
    retn.insert(QLatin1String("Democratic_Republic_of_the_Congo"), democratic_republic_of_the_congo_bb);

    BoundingBox djibouti_bb;
    djibouti_bb.latShift = 0.0;
    djibouti_bb.lonShift = 0.0;
    djibouti_bb.lowerLeft.lat = 10.926;
    djibouti_bb.lowerLeft.lon = 41.662;
    djibouti_bb.upperRight.lat = 12.699;
    djibouti_bb.upperRight.lon = 43.318;
    retn.insert(QLatin1String("Djibouti"), djibouti_bb);

    BoundingBox egypt_bb;
    egypt_bb.latShift = 0.0;
    egypt_bb.lonShift = 0.0;
    egypt_bb.lowerLeft.lat = 22.0;
    egypt_bb.lowerLeft.lon = 24.700;
    egypt_bb.upperRight.lat = 31.586;
    egypt_bb.upperRight.lon = 36.866;
    retn.insert(QLatin1String("Egypt"), egypt_bb);

    BoundingBox equatorial_guinea_bb;
    equatorial_guinea_bb.latShift = 0.0;
    equatorial_guinea_bb.lonShift = 0.0;
    equatorial_guinea_bb.lowerLeft.lat = 1.010;
    equatorial_guinea_bb.lowerLeft.lon = 9.306;
    equatorial_guinea_bb.upperRight.lat = 2.284;
    equatorial_guinea_bb.upperRight.lon = 11.285;
    retn.insert(QLatin1String("Equatorial_Guinea"), equatorial_guinea_bb);

    BoundingBox eritrea_bb;
    eritrea_bb.latShift = 0.0;
    eritrea_bb.lonShift = 0.0;
    eritrea_bb.lowerLeft.lat = 12.455;
    eritrea_bb.lowerLeft.lon = 36.323;
    eritrea_bb.upperRight.lat = 17.998;
    eritrea_bb.upperRight.lon = 43.0812;
    retn.insert(QLatin1String("Eritrea"), eritrea_bb);

    BoundingBox ethiopia_bb;
    ethiopia_bb.latShift = 0.0;
    ethiopia_bb.lonShift = 0.0;
    ethiopia_bb.lowerLeft.lat = 3.422;
    ethiopia_bb.lowerLeft.lon = 32.954;
    ethiopia_bb.upperRight.lat = 14.959;
    ethiopia_bb.upperRight.lon = 47.789;
    retn.insert(QLatin1String("Ethiopia"), ethiopia_bb);

    BoundingBox gabon_bb;
    gabon_bb.latShift = 0.0;
    gabon_bb.lonShift = 0.0;
    gabon_bb.lowerLeft.lat = -3.978;
    gabon_bb.lowerLeft.lon = 8.798;
    gabon_bb.upperRight.lat = 2.327;
    gabon_bb.upperRight.lon = 14.425;
    retn.insert(QLatin1String("Gabon"), gabon_bb);

    BoundingBox gambia_bb;
    gambia_bb.latShift = 0.0;
    gambia_bb.lonShift = 0.0;
    gambia_bb.lowerLeft.lat = 13.130;
    gambia_bb.lowerLeft.lon = -16.841;
    gambia_bb.upperRight.lat = 13.876;
    gambia_bb.upperRight.lon = -13.845;
    retn.insert(QLatin1String("Gambia"), gambia_bb);

    BoundingBox ghana_bb;
    ghana_bb.latShift = 0.0;
    ghana_bb.lonShift = 0.0;
    ghana_bb.lowerLeft.lat = 4.710;
    ghana_bb.lowerLeft.lon = -3.244;
    ghana_bb.upperRight.lat = 11.098;
    ghana_bb.upperRight.lon = 1.060;
    retn.insert(QLatin1String("Ghana"), ghana_bb);

    BoundingBox guinea_bb;
    guinea_bb.latShift = 0.0;
    guinea_bb.lonShift = 0.0;
    guinea_bb.lowerLeft.lat = 7.309;
    guinea_bb.lowerLeft.lon = -15.130;
    guinea_bb.upperRight.lat = 12.586;
    guinea_bb.upperRight.lon = -7.832;
    retn.insert(QLatin1String("Guinea"), guinea_bb);

    BoundingBox guinea_bissau_bb;
    guinea_bissau_bb.latShift = 0.0;
    guinea_bissau_bb.lonShift = 0.0;
    guinea_bissau_bb.lowerLeft.lat = 11.040;
    guinea_bissau_bb.lowerLeft.lon = -16.677;
    guinea_bissau_bb.upperRight.lat = 12.628;
    guinea_bissau_bb.upperRight.lon = -13.700;
    retn.insert(QLatin1String("Guinea_Bissau"), guinea_bissau_bb);

    BoundingBox ivory_coast_bb;
    ivory_coast_bb.latShift = 0.0;
    ivory_coast_bb.lonShift = 0.0;
    ivory_coast_bb.lowerLeft.lat = 4.338;
    ivory_coast_bb.lowerLeft.lon = -8.602;
    ivory_coast_bb.upperRight.lat = 10.524;
    ivory_coast_bb.upperRight.lon = -2.562;
    retn.insert(QLatin1String("Ivory_Coast"), ivory_coast_bb);

    BoundingBox kenya_bb;
    kenya_bb.latShift = 0.0;
    kenya_bb.lonShift = 0.0;
    kenya_bb.lowerLeft.lat = -4.676;
    kenya_bb.lowerLeft.lon = 33.893;
    kenya_bb.upperRight.lat = 5.506;
    kenya_bb.upperRight.lon = 41.855;
    retn.insert(QLatin1String("Kenya"), kenya_bb);

    BoundingBox lesotho_bb;
    lesotho_bb.latShift = 0.0;
    lesotho_bb.lonShift = 0.0;
    lesotho_bb.lowerLeft.lat = -30.645;
    lesotho_bb.lowerLeft.lon = 26.999;
    lesotho_bb.upperRight.lat = -28.648;
    lesotho_bb.upperRight.lon = 29.325;
    retn.insert(QLatin1String("Lesotho"), lesotho_bb);

    BoundingBox liberia_bb;
    liberia_bb.latShift = 0.0;
    liberia_bb.lonShift = 0.0;
    liberia_bb.lowerLeft.lat = 4.356;
    liberia_bb.lowerLeft.lon = -11.439;
    liberia_bb.upperRight.lat = 8.541;
    liberia_bb.upperRight.lon = -7.540;
    retn.insert(QLatin1String("Liberia"), liberia_bb);

    BoundingBox libya_bb;
    libya_bb.latShift = 0.0;
    libya_bb.lonShift = 0.0;
    libya_bb.lowerLeft.lat = 19.580;
    libya_bb.lowerLeft.lon = 9.319;
    libya_bb.upperRight.lat = 33.137;
    libya_bb.upperRight.lon = 25.165;
    retn.insert(QLatin1String("Libya"), libya_bb);

    BoundingBox madagascar_bb;
    madagascar_bb.latShift = 0.0;
    madagascar_bb.lonShift = 0.0;
    madagascar_bb.lowerLeft.lat = -25.601;
    madagascar_bb.lowerLeft.lon = 43.254;
    madagascar_bb.upperRight.lat = -12.041;
    madagascar_bb.upperRight.lon = 50.477;
    retn.insert(QLatin1String("Madagascar"), madagascar_bb);

    BoundingBox madeira_bb;
    madeira_bb.latShift = 0.0;
    madeira_bb.lonShift = 0.0;
    madeira_bb.lowerLeft.lat = 30.028;
    madeira_bb.lowerLeft.lon = -17.266;
    madeira_bb.upperRight.lat = 33.117;
    madeira_bb.upperRight.lon = -15.853;
    retn.insert(QLatin1String("Madeira"), madeira_bb);

    BoundingBox malawi_bb;
    malawi_bb.latShift = 0.0;
    malawi_bb.lonShift = 0.0;
    malawi_bb.lowerLeft.lat = -16.801;
    malawi_bb.lowerLeft.lon = 32.688;
    malawi_bb.upperRight.lat = -9.231;
    malawi_bb.upperRight.lon = 35.772;
    retn.insert(QLatin1String("Malawi"), malawi_bb);

    BoundingBox mali_bb;
    mali_bb.latShift = 0.0;
    mali_bb.lonShift = 0.0;
    mali_bb.lowerLeft.lat = 10.096;
    mali_bb.lowerLeft.lon = -12.170;
    mali_bb.upperRight.lat = 24.975;
    mali_bb.upperRight.lon = 4.270;
    retn.insert(QLatin1String("Mali"), mali_bb);

    BoundingBox mauritania_bb;
    mauritania_bb.latShift = 0.0;
    mauritania_bb.lonShift = 0.0;
    mauritania_bb.lowerLeft.lat = 14.617;
    mauritania_bb.lowerLeft.lon = -17.063;
    mauritania_bb.upperRight.lat = 27.396;
    mauritania_bb.upperRight.lon = -4.923;
    retn.insert(QLatin1String("Mauritania"), mauritania_bb);

    BoundingBox mauritius_bb;
    mauritius_bb.latShift = 0.0;
    mauritius_bb.lonShift = 0.0;
    mauritius_bb.lowerLeft.lat = -20.526;
    mauritius_bb.lowerLeft.lon = 56.513;
    mauritius_bb.upperRight.lat = -10.319;
    mauritius_bb.upperRight.lon = 63.525;
    retn.insert(QLatin1String("Mauritius"), mauritius_bb);

    BoundingBox mayotte_bb;
    mayotte_bb.latShift = 0.0;
    mayotte_bb.lonShift = 0.0;
    mayotte_bb.lowerLeft.lat = -13.000;
    mayotte_bb.lowerLeft.lon = 45.014;
    mayotte_bb.upperRight.lat = -12.633;
    mayotte_bb.upperRight.lon = 45.317;
    retn.insert(QLatin1String("Mayotte"), mayotte_bb);

    BoundingBox melilla_bb;
    melilla_bb.latShift = 0.0;
    melilla_bb.lonShift = 0.0;
    melilla_bb.lowerLeft.lat = 35.269;
    melilla_bb.lowerLeft.lon = -2.963;
    melilla_bb.upperRight.lat = 35.307;
    melilla_bb.upperRight.lon = -2.923;
    retn.insert(QLatin1String("Melilla"), melilla_bb);

    BoundingBox morocco_bb;
    morocco_bb.latShift = 0.0;
    morocco_bb.lonShift = 0.0;
    morocco_bb.lowerLeft.lat = 21.421;
    morocco_bb.lowerLeft.lon = -17.020;
    morocco_bb.upperRight.lat = 35.760;
    morocco_bb.upperRight.lon = -1.125;
    retn.insert(QLatin1String("Morocco"), morocco_bb);

    BoundingBox mozambique_bb;
    mozambique_bb.latShift = 0.0;
    mozambique_bb.lonShift = 0.0;
    mozambique_bb.lowerLeft.lat = -26.742;
    mozambique_bb.lowerLeft.lon = 30.179;
    mozambique_bb.upperRight.lat = -10.317;
    mozambique_bb.upperRight.lon = 40.775;
    retn.insert(QLatin1String("Mozambique"), mozambique_bb);

    BoundingBox namibia_bb;
    namibia_bb.latShift = 0.0;
    namibia_bb.lonShift = 0.0;
    namibia_bb.lowerLeft.lat = -29.045;
    namibia_bb.lowerLeft.lon = 11.734;
    namibia_bb.upperRight.lat = -16.941;
    namibia_bb.upperRight.lon = 25.084;
    retn.insert(QLatin1String("Namibia"), namibia_bb);

    BoundingBox niger_bb;
    niger_bb.latShift = 0.0;
    niger_bb.lonShift = 0.0;
    niger_bb.lowerLeft.lat = 11.660;
    niger_bb.lowerLeft.lon = 0.296;
    niger_bb.upperRight.lat = 23.472;
    niger_bb.upperRight.lon = 15.903;
    retn.insert(QLatin1String("Niger"), niger_bb);

    BoundingBox nigeria_bb;
    nigeria_bb.latShift = 0.0;
    nigeria_bb.lonShift = 0.0;
    nigeria_bb.lowerLeft.lat = 4.240;
    nigeria_bb.lowerLeft.lon = 2.691;
    nigeria_bb.upperRight.lat = 13.866;
    nigeria_bb.upperRight.lon = 14.577;
    retn.insert(QLatin1String("Nigeria"), nigeria_bb);

    BoundingBox reunion_bb;
    reunion_bb.latShift = 0.0;
    reunion_bb.lonShift = 0.0;
    reunion_bb.lowerLeft.lat = -21.372;
    reunion_bb.lowerLeft.lon = 55.219;
    reunion_bb.upperRight.lat = -20.856;
    reunion_bb.upperRight.lon = 55.845;
    retn.insert(QLatin1String("Reunion"), reunion_bb);

    BoundingBox rwanda_bb;
    rwanda_bb.latShift = 0.0;
    rwanda_bb.lonShift = 0.0;
    rwanda_bb.lowerLeft.lat = -2.918;
    rwanda_bb.lowerLeft.lon = 29.024;
    rwanda_bb.upperRight.lat = -1.137;
    rwanda_bb.upperRight.lon = 30.816;
    retn.insert(QLatin1String("Rwanda"), rwanda_bb);

    BoundingBox sao_tome_and_principe_bb;
    sao_tome_and_principe_bb.latShift = 0.0;
    sao_tome_and_principe_bb.lonShift = 0.0;
    sao_tome_and_principe_bb.lowerLeft.lat = -0.014;
    sao_tome_and_principe_bb.lowerLeft.lon = 5.599;
    sao_tome_and_principe_bb.upperRight.lat = 1.734;
    sao_tome_and_principe_bb.upperRight.lon = 7.466;
    retn.insert(QLatin1String("Sao_Tome_and_Principe"), sao_tome_and_principe_bb);

    BoundingBox senegal_bb;
    senegal_bb.latShift = 0.0;
    senegal_bb.lonShift = 0.0;
    senegal_bb.lowerLeft.lat = 12.332;
    senegal_bb.lowerLeft.lon = -17.625;
    senegal_bb.upperRight.lat = 16.598;
    senegal_bb.upperRight.lon = -11.467;
    retn.insert(QLatin1String("Senegal"), senegal_bb);

    BoundingBox seychelles_bb;
    seychelles_bb.latShift = 0.0;
    seychelles_bb.lonShift = 0.0;
    seychelles_bb.lowerLeft.lat = -10.217;
    seychelles_bb.lowerLeft.lon = 46.199;
    seychelles_bb.upperRight.lat = -3.711;
    seychelles_bb.upperRight.lon = 56.279;
    retn.insert(QLatin1String("Seychelles"), seychelles_bb);

    BoundingBox sierra_leone_bb;
    sierra_leone_bb.latShift = 0.0;
    sierra_leone_bb.lonShift = 0.0;
    sierra_leone_bb.lowerLeft.lat = 6.785;
    sierra_leone_bb.lowerLeft.lon = -13.247;
    sierra_leone_bb.upperRight.lat = 10.047;
    sierra_leone_bb.upperRight.lon = -10.230;
    retn.insert(QLatin1String("Sierra_Leone"), sierra_leone_bb);

    BoundingBox somalia_bb;
    somalia_bb.latShift = 0.0;
    somalia_bb.lonShift = 0.0;
    somalia_bb.lowerLeft.lat = -1.683;
    somalia_bb.lowerLeft.lon = 40.981;
    somalia_bb.upperRight.lat = 12.025;
    somalia_bb.upperRight.lon = 51.134;
    retn.insert(QLatin1String("Somalia"), somalia_bb);

    BoundingBox south_africa_bb;
    south_africa_bb.latShift = 0.0;
    south_africa_bb.lonShift = 0.0;
    south_africa_bb.lowerLeft.lat = -34.819;
    south_africa_bb.lowerLeft.lon = 16.345;
    south_africa_bb.upperRight.lat = -22.091;
    south_africa_bb.upperRight.lon = 32.830;
    retn.insert(QLatin1String("South_Africa"), south_africa_bb);

    BoundingBox south_sudan_bb;
    south_sudan_bb.latShift = 0.0;
    south_sudan_bb.lonShift = 0.0;
    south_sudan_bb.lowerLeft.lat = 3.509;
    south_sudan_bb.lowerLeft.lon = 23.887;
    south_sudan_bb.upperRight.lat = 12.248;
    south_sudan_bb.upperRight.lon = 35.298;
    retn.insert(QLatin1String("South_Sudan"), south_sudan_bb);

    BoundingBox sudan_bb;
    sudan_bb.latShift = 0.0;
    sudan_bb.lonShift = 0.0;
    sudan_bb.lowerLeft.lat = 8.620;
    sudan_bb.lowerLeft.lon = 21.937;
    sudan_bb.upperRight.lat = 22.0;
    sudan_bb.upperRight.lon = 38.410;
    retn.insert(QLatin1String("Sudan"), sudan_bb);

    BoundingBox swaziland_bb;
    swaziland_bb.latShift = 0.0;
    swaziland_bb.lonShift = 0.0;
    swaziland_bb.lowerLeft.lat = -27.286;
    swaziland_bb.lowerLeft.lon = 30.676;
    swaziland_bb.upperRight.lat = -25.660;
    swaziland_bb.upperRight.lon = 32.072;
    retn.insert(QLatin1String("Swaziland"), swaziland_bb);

    BoundingBox tanzania_bb;
    tanzania_bb.latShift = 0.0;
    tanzania_bb.lonShift = 0.0;
    tanzania_bb.lowerLeft.lat = -11.720;
    tanzania_bb.lowerLeft.lon = 29.340;
    tanzania_bb.upperRight.lat = -0.95;
    tanzania_bb.upperRight.lon = 40.317;
    retn.insert(QLatin1String("Tanzania"), tanzania_bb);

    BoundingBox togo_bb;
    togo_bb.latShift = 0.0;
    togo_bb.lonShift = 0.0;
    togo_bb.lowerLeft.lat = 5.929;
    togo_bb.lowerLeft.lon = -0.049;
    togo_bb.upperRight.lat = 11.018;
    togo_bb.upperRight.lon = 1.865;
    retn.insert(QLatin1String("Togo"), togo_bb);

    BoundingBox tunisia_bb;
    tunisia_bb.latShift = 0.0;
    tunisia_bb.lonShift = 0.0;
    tunisia_bb.lowerLeft.lat = 30.307;
    tunisia_bb.lowerLeft.lon = 7.524;
    tunisia_bb.upperRight.lat = 37.350;
    tunisia_bb.upperRight.lon = 11.489;
    retn.insert(QLatin1String("Tunisia"), tunisia_bb);

    BoundingBox uganda_bb;
    uganda_bb.latShift = 0.0;
    uganda_bb.lonShift = 0.0;
    uganda_bb.lowerLeft.lat = -1.443;
    uganda_bb.lowerLeft.lon = 29.579;
    uganda_bb.upperRight.lat = 4.249;
    uganda_bb.upperRight.lon = 35.035;
    retn.insert(QLatin1String("Uganda"), uganda_bb);

    BoundingBox zambia_bb;
    zambia_bb.latShift = 0.0;
    zambia_bb.lonShift = 0.0;
    zambia_bb.lowerLeft.lat = -17.961;
    zambia_bb.lowerLeft.lon = 21.888;
    zambia_bb.upperRight.lat = -8.238;
    zambia_bb.upperRight.lon = 33.485;
    retn.insert(QLatin1String("Zambia"), zambia_bb);

    BoundingBox zimbabwe_bb;
    zimbabwe_bb.latShift = 0.0;
    zimbabwe_bb.lonShift = 0.0;
    zimbabwe_bb.lowerLeft.lat = -22.271;
    zimbabwe_bb.lowerLeft.lon = 25.264;
    zimbabwe_bb.upperRight.lat = -15.508;
    zimbabwe_bb.upperRight.lon = 32.850;
    retn.insert(QLatin1String("Zimbabwe"), zimbabwe_bb);

// Asia

    BoundingBox afghanistan_bb;
    afghanistan_bb.latShift = 0.0;
    afghanistan_bb.lonShift = 0.0;
    afghanistan_bb.lowerLeft.lat = 29.319;
    afghanistan_bb.lowerLeft.lon = 60.528;
    afghanistan_bb.upperRight.lat = 38.486;
    afghanistan_bb.upperRight.lon = 75.158;
    retn.insert(QLatin1String("Afghanistan"), afghanistan_bb);

    BoundingBox bahrain_bb;
    bahrain_bb.latShift = 0.0;
    bahrain_bb.lonShift = 0.0;
    bahrain_bb.lowerLeft.lat = 25.542;
    bahrain_bb.lowerLeft.lon = 50.386;
    bahrain_bb.upperRight.lat = 26.292;
    bahrain_bb.upperRight.lon = 50.828;
    retn.insert(QLatin1String("Bahrain"), bahrain_bb);

    BoundingBox bangladesh_bb;
    bangladesh_bb.latShift = 0.0;
    bangladesh_bb.lonShift = 0.0;
    bangladesh_bb.lowerLeft.lat = 20.671;
    bangladesh_bb.lowerLeft.lon = 88.085;
    bangladesh_bb.upperRight.lat = 26.447;
    bangladesh_bb.upperRight.lon = 92.673;
    retn.insert(QLatin1String("Bangladesh"), bangladesh_bb);

    BoundingBox bhutan_bb;
    bhutan_bb.latShift = 0.0;
    bhutan_bb.lonShift = 0.0;
    bhutan_bb.lowerLeft.lat = 26.719;
    bhutan_bb.lowerLeft.lon = 88.814;
    bhutan_bb.upperRight.lat = 28.296;
    bhutan_bb.upperRight.lon = 92.104;
    retn.insert(QLatin1String("Bhutan"), bhutan_bb);

    BoundingBox brunei_bb;
    brunei_bb.latShift = 0.0;
    brunei_bb.lonShift = 0.0;
    brunei_bb.lowerLeft.lat = 4.008;
    brunei_bb.lowerLeft.lon = 114.204;
    brunei_bb.upperRight.lat = 5.448;
    brunei_bb.upperRight.lon = 115.451;
    retn.insert(QLatin1String("Brunei"), brunei_bb);

    BoundingBox cambodia_bb;
    cambodia_bb.latShift = 0.0;
    cambodia_bb.lonShift = 0.0;
    cambodia_bb.lowerLeft.lat = 10.487;
    cambodia_bb.lowerLeft.lon = 102.348;
    cambodia_bb.upperRight.lat = 14.571;
    cambodia_bb.upperRight.lon = 107.615;
    retn.insert(QLatin1String("Cambodia"), cambodia_bb);

    BoundingBox china_bb;
    china_bb.latShift = 0.0;
    china_bb.lonShift = 0.0;
    china_bb.lowerLeft.lat = 18.198;
    china_bb.lowerLeft.lon = 73.675;
    china_bb.upperRight.lat = 53.459;
    china_bb.upperRight.lon = 135.026;
    retn.insert(QLatin1String("China"), china_bb);

    BoundingBox east_timor_bb;
    east_timor_bb.latShift = 0.0;
    east_timor_bb.lonShift = 0.0;
    east_timor_bb.lowerLeft.lat = -9.393;
    east_timor_bb.lowerLeft.lon = 124.969;
    east_timor_bb.upperRight.lat = -8.273;
    east_timor_bb.upperRight.lon = 127.336;
    retn.insert(QLatin1String("East_Timor"), east_timor_bb);

    BoundingBox india_bb;
    india_bb.latShift = 0.0;
    india_bb.lonShift = 0.0;
    india_bb.lowerLeft.lat = 6.0;
    india_bb.lowerLeft.lon = 65.0;
    india_bb.upperRight.lat = 35.956;
    india_bb.upperRight.lon = 97.35;
    retn.insert(QLatin1String("India"), india_bb);

    BoundingBox indonesia_bb;
    indonesia_bb.latShift = 0.0;
    indonesia_bb.lonShift = 0.0;
    indonesia_bb.lowerLeft.lat = -10.360;
    indonesia_bb.lowerLeft.lon = 95.293;
    indonesia_bb.upperRight.lat = 5.480;
    indonesia_bb.upperRight.lon = 141.034;
    retn.insert(QLatin1String("Indonesia"), indonesia_bb);

    BoundingBox iran_bb;
    iran_bb.latShift = 0.0;
    iran_bb.lonShift = 0.0;
    iran_bb.lowerLeft.lat = 25.078;
    iran_bb.lowerLeft.lon = 44.109;
    iran_bb.upperRight.lat = 39.713;
    iran_bb.upperRight.lon = 63.316;
    retn.insert(QLatin1String("Iran"), iran_bb);

    BoundingBox iraq_bb;
    iraq_bb.latShift = 0.0;
    iraq_bb.lonShift = 0.0;
    iraq_bb.lowerLeft.lat = 29.1;
    iraq_bb.lowerLeft.lon = 38.792;
    iraq_bb.upperRight.lat = 37.385;
    iraq_bb.upperRight.lon = 48.568;
    retn.insert(QLatin1String("Iraq"), iraq_bb);

    BoundingBox israel_bb;
    israel_bb.latShift = 0.0;
    israel_bb.lonShift = 0.0;
    israel_bb.lowerLeft.lat = 29.501;
    israel_bb.lowerLeft.lon = 34.265;
    israel_bb.upperRight.lat = 33.277;
    israel_bb.upperRight.lon = 35.836;
    retn.insert(QLatin1String("Israel"), israel_bb);

    BoundingBox japan_bb;
    japan_bb.latShift = 0.0;
    japan_bb.lonShift = 0.0;
    japan_bb.lowerLeft.lat = 31.030;
    japan_bb.lowerLeft.lon = 129.401;
    japan_bb.upperRight.lat = 45.551;
    japan_bb.upperRight.lon = 145.543;
    retn.insert(QLatin1String("Japan"), japan_bb);

    BoundingBox jordan_bb;
    jordan_bb.latShift = 0.0;
    jordan_bb.lonShift = 0.0;
    jordan_bb.lowerLeft.lat = 29.197;
    jordan_bb.lowerLeft.lon = 34.922;
    jordan_bb.upperRight.lat = 33.379;
    jordan_bb.upperRight.lon = 39.195;
    retn.insert(QLatin1String("Jordan"), jordan_bb);

    BoundingBox kuwait_bb;
    kuwait_bb.latShift = 0.0;
    kuwait_bb.lonShift = 0.0;
    kuwait_bb.lowerLeft.lat = 28.526;
    kuwait_bb.lowerLeft.lon = 46.569;
    kuwait_bb.upperRight.lat = 30.059;
    kuwait_bb.upperRight.lon = 48.416;
    retn.insert(QLatin1String("Kuwait"), kuwait_bb);

    BoundingBox kyrgyzstan_bb;
    kyrgyzstan_bb.latShift = 0.0;
    kyrgyzstan_bb.lonShift = 0.0;
    kyrgyzstan_bb.lowerLeft.lat = 39.279;
    kyrgyzstan_bb.lowerLeft.lon = 69.465;
    kyrgyzstan_bb.upperRight.lat = 43.298;
    kyrgyzstan_bb.upperRight.lon = 80.260;
    retn.insert(QLatin1String("Kyrgyzstan"), kyrgyzstan_bb);

    BoundingBox laos_bb;
    laos_bb.latShift = 0.0;
    laos_bb.lonShift = 0.0;
    laos_bb.lowerLeft.lat = 13.881;
    laos_bb.lowerLeft.lon = 100.115;
    laos_bb.upperRight.lat = 22.465;
    laos_bb.upperRight.lon = 107.565;
    retn.insert(QLatin1String("Laos"), laos_bb);

    BoundingBox lebanon_bb;
    lebanon_bb.latShift = 0.0;
    lebanon_bb.lonShift = 0.0;
    lebanon_bb.lowerLeft.lat = 33.089;
    lebanon_bb.lowerLeft.lon = 35.126;
    lebanon_bb.upperRight.lat = 34.645;
    lebanon_bb.upperRight.lon = 36.612;
    retn.insert(QLatin1String("Lebanon"), lebanon_bb);

    BoundingBox malaysia_bb;
    malaysia_bb.latShift = 0.0;
    malaysia_bb.lonShift = 0.0;
    malaysia_bb.lowerLeft.lat = 0.773;
    malaysia_bb.lowerLeft.lon = 100.086;
    malaysia_bb.upperRight.lat = 6.928;
    malaysia_bb.upperRight.lon = 119.182;
    retn.insert(QLatin1String("Malaysia"), malaysia_bb);

    BoundingBox maldives_bb;
    maldives_bb.latShift = 0.0;
    maldives_bb.lonShift = 0.0;
    maldives_bb.lowerLeft.lat = -2.9;
    maldives_bb.lowerLeft.lon = 72.616;
    maldives_bb.upperRight.lat = 7.117;
    maldives_bb.upperRight.lon = 73.767;
    retn.insert(QLatin1String("Maldives"), maldives_bb);

    BoundingBox mongolia_bb;
    mongolia_bb.latShift = 0.0;
    mongolia_bb.lonShift = 0.0;
    mongolia_bb.lowerLeft.lat = 41.597;
    mongolia_bb.lowerLeft.lon = 87.751;
    mongolia_bb.upperRight.lat = 52.047;
    mongolia_bb.upperRight.lon = 119.773;
    retn.insert(QLatin1String("Mongolia"), mongolia_bb);

    BoundingBox myanmar_bb;
    myanmar_bb.latShift = 0.0;
    myanmar_bb.lonShift = 0.0;
    myanmar_bb.lowerLeft.lat = 9.932;
    myanmar_bb.lowerLeft.lon = 92.303;
    myanmar_bb.upperRight.lat = 28.336;
    myanmar_bb.upperRight.lon = 101.180;
    retn.insert(QLatin1String("Myanmar"), myanmar_bb);

    BoundingBox nepal_bb;
    nepal_bb.latShift = 0.0;
    nepal_bb.lonShift = 0.0;
    nepal_bb.lowerLeft.lat = 26.398;
    nepal_bb.lowerLeft.lon = 80.088;
    nepal_bb.upperRight.lat = 30.423;
    nepal_bb.upperRight.lon = 88.174;
    retn.insert(QLatin1String("Nepal"), nepal_bb);

    BoundingBox north_korea_bb;
    north_korea_bb.latShift = 0.0;
    north_korea_bb.lonShift = 0.0;
    north_korea_bb.lowerLeft.lat = 37.669;
    north_korea_bb.lowerLeft.lon = 124.266;
    north_korea_bb.upperRight.lat = 42.985;
    north_korea_bb.upperRight.lon = 130.78;
    retn.insert(QLatin1String("North_Korea"), north_korea_bb);

    BoundingBox oman_bb;
    oman_bb.latShift = 0.0;
    oman_bb.lonShift = 0.0;
    oman_bb.lowerLeft.lat = 16.651;
    oman_bb.lowerLeft.lon = 52.0;
    oman_bb.upperRight.lat = 26.396;
    oman_bb.upperRight.lon = 59.808;
    retn.insert(QLatin1String("Oman"), oman_bb);

    BoundingBox pakistan_bb;
    pakistan_bb.latShift = 0.0;
    pakistan_bb.lonShift = 0.0;
    pakistan_bb.lowerLeft.lat = 23.692;
    pakistan_bb.lowerLeft.lon = 60.874;
    pakistan_bb.upperRight.lat = 37.133;
    pakistan_bb.upperRight.lon = 77.837;
    retn.insert(QLatin1String("Pakistan"), pakistan_bb);

    BoundingBox palestine_bb;
    palestine_bb.latShift = 0.0;
    palestine_bb.lonShift = 0.0;
    palestine_bb.lowerLeft.lat = 31.223;
    palestine_bb.lowerLeft.lon = 34.23;
    palestine_bb.upperRight.lat = 33.34;
    palestine_bb.upperRight.lon = 35.876;
    retn.insert(QLatin1String("Palestine"), palestine_bb);

    BoundingBox philippines_bb;
    philippines_bb.latShift = 0.0;
    philippines_bb.lonShift = 0.0;
    philippines_bb.lowerLeft.lat = 5.581;
    philippines_bb.lowerLeft.lon = 117.174;
    philippines_bb.upperRight.lat = 18.505;
    philippines_bb.upperRight.lon = 126.537;
    retn.insert(QLatin1String("Philippines"), philippines_bb);

    BoundingBox qatar_bb;
    qatar_bb.latShift = 0.0;
    qatar_bb.lonShift = 0.0;
    qatar_bb.lowerLeft.lat = 24.556;
    qatar_bb.lowerLeft.lon = 50.744;
    qatar_bb.upperRight.lat = 26.115;
    qatar_bb.upperRight.lon = 51.607;
    retn.insert(QLatin1String("Qatar"), qatar_bb);

    BoundingBox russia_bb;
    russia_bb.latShift = 0.0;
    russia_bb.lonShift = 0.0;
    russia_bb.lowerLeft.lat = 41.151;
    russia_bb.lowerLeft.lon = 19.639;
    russia_bb.upperRight.lat = 81.25;
    russia_bb.upperRight.lon = -168.997;
    retn.insert(QLatin1String("Russia"), russia_bb);

    BoundingBox saudi_arabia_bb;
    saudi_arabia_bb.latShift = 0.0;
    saudi_arabia_bb.lonShift = 0.0;
    saudi_arabia_bb.lowerLeft.lat = 16.347;
    saudi_arabia_bb.lowerLeft.lon = 34.632;
    saudi_arabia_bb.upperRight.lat = 32.161;
    saudi_arabia_bb.upperRight.lon = 55.666;
    retn.insert(QLatin1String("Saudi_Arabia"), saudi_arabia_bb);

    BoundingBox singapore_bb;
    singapore_bb.latShift = 0.0;
    singapore_bb.lonShift = 0.0;
    singapore_bb.lowerLeft.lat = 1.115;
    singapore_bb.lowerLeft.lon = 103.618;
    singapore_bb.upperRight.lat = 1.471;
    singapore_bb.upperRight.lon = 104.408;
    retn.insert(QLatin1String("Singapore"), singapore_bb);

    BoundingBox south_korea_bb;
    south_korea_bb.latShift = 0.0;
    south_korea_bb.lonShift = 0.0;
    south_korea_bb.lowerLeft.lat = 34.39;
    south_korea_bb.lowerLeft.lon = 126.117;
    south_korea_bb.upperRight.lat = 38.612;
    south_korea_bb.upperRight.lon = 129.468;
    retn.insert(QLatin1String("South_Korea"), south_korea_bb);

    BoundingBox sri_lanka_bb;
    sri_lanka_bb.latShift = 0.0;
    sri_lanka_bb.lonShift = 0.0;
    sri_lanka_bb.lowerLeft.lat = 5.968;
    sri_lanka_bb.lowerLeft.lon = 79.695;
    sri_lanka_bb.upperRight.lat = 9.824;
    sri_lanka_bb.upperRight.lon = 81.780;
    retn.insert(QLatin1String("Sri_Lanka"), sri_lanka_bb);

    BoundingBox syria_bb;
    syria_bb.latShift = 0.0;
    syria_bb.lonShift = 0.0;
    syria_bb.lowerLeft.lat = 32.312;
    syria_bb.lowerLeft.lon = 35.7;
    syria_bb.upperRight.lat = 37.23;
    syria_bb.upperRight.lon = 42.35;
    retn.insert(QLatin1String("Syria"), syria_bb);

    BoundingBox taiwan_bb;
    taiwan_bb.latShift = 0.0;
    taiwan_bb.lonShift = 0.0;
    taiwan_bb.lowerLeft.lat = 21.971;
    taiwan_bb.lowerLeft.lon = 120.106;
    taiwan_bb.upperRight.lat = 25.295;
    taiwan_bb.upperRight.lon = 121.951;
    retn.insert(QLatin1String("Taiwan"), taiwan_bb);

    BoundingBox tajikistan_bb;
    tajikistan_bb.latShift = 0.0;
    tajikistan_bb.lonShift = 0.0;
    tajikistan_bb.lowerLeft.lat = 36.738;
    tajikistan_bb.lowerLeft.lon = 67.442;
    tajikistan_bb.upperRight.lat = 40.96;
    tajikistan_bb.upperRight.lon = 74.98;
    retn.insert(QLatin1String("Tajikistan"), tajikistan_bb);

    BoundingBox thailand_bb;
    thailand_bb.latShift = 0.0;
    thailand_bb.lonShift = 0.0;
    thailand_bb.lowerLeft.lat = 5.691;
    thailand_bb.lowerLeft.lon = 97.376;
    thailand_bb.upperRight.lat = 20.417;
    thailand_bb.upperRight.lon = 105.589;
    retn.insert(QLatin1String("Thailand"), thailand_bb);

    BoundingBox turkey_bb;
    turkey_bb.latShift = 0.0;
    turkey_bb.lonShift = 0.0;
    turkey_bb.lowerLeft.lat = 35.821;
    turkey_bb.lowerLeft.lon = 26.043;
    turkey_bb.upperRight.lat = 42.141;
    turkey_bb.upperRight.lon = 44.794;
    retn.insert(QLatin1String("Turkey"), turkey_bb);

    BoundingBox turkmenistan_bb;
    turkmenistan_bb.latShift = 0.0;
    turkmenistan_bb.lonShift = 0.0;
    turkmenistan_bb.lowerLeft.lat = 35.271;
    turkmenistan_bb.lowerLeft.lon = 52.502;
    turkmenistan_bb.upperRight.lat = 42.752;
    turkmenistan_bb.upperRight.lon = 66.546;
    retn.insert(QLatin1String("Turkmenistan"), turkmenistan_bb);

    BoundingBox united_arab_emirates_bb;
    united_arab_emirates_bb.latShift = 0.0;
    united_arab_emirates_bb.lonShift = 0.0;
    united_arab_emirates_bb.lowerLeft.lat = 22.497;
    united_arab_emirates_bb.lowerLeft.lon = 51.58;
    united_arab_emirates_bb.upperRight.lat = 26.055;
    united_arab_emirates_bb.upperRight.lon = 56.396;
    retn.insert(QLatin1String("United_Arab_Emirates"), united_arab_emirates_bb);

    BoundingBox uzbekistan_bb;
    uzbekistan_bb.latShift = 0.0;
    uzbekistan_bb.lonShift = 0.0;
    uzbekistan_bb.lowerLeft.lat = 37.145;
    uzbekistan_bb.lowerLeft.lon = 55.929;
    uzbekistan_bb.upperRight.lat = 45.587;
    uzbekistan_bb.upperRight.lon = 73.055;
    retn.insert(QLatin1String("Uzbekistan"), uzbekistan_bb);

    BoundingBox vietnam_bb;
    vietnam_bb.latShift = 0.0;
    vietnam_bb.lonShift = 0.0;
    vietnam_bb.lowerLeft.lat = 8.6;
    vietnam_bb.lowerLeft.lon = 102.17;
    vietnam_bb.upperRight.lat = 23.352;
    vietnam_bb.upperRight.lon = 109.335;
    retn.insert(QLatin1String("Vietnam"), vietnam_bb);

    BoundingBox yemen_bb;
    yemen_bb.latShift = 0.0;
    yemen_bb.lonShift = 0.0;
    yemen_bb.lowerLeft.lat = 12.586;
    yemen_bb.lowerLeft.lon = 42.605;
    yemen_bb.upperRight.lat = 19.0;
    yemen_bb.upperRight.lon = 53.11;
    retn.insert(QLatin1String("Yemen"), yemen_bb);

// Europe

    BoundingBox aland_islands_bb;
    aland_islands_bb.latShift = 0.0;
    aland_islands_bb.lonShift = 0.0;
    aland_islands_bb.lowerLeft.lat = 59.736;
    aland_islands_bb.lowerLeft.lon = 19.263;
    aland_islands_bb.upperRight.lat = 60.666;
    aland_islands_bb.upperRight.lon = 21.324;
    retn.insert(QLatin1String("Aland_Islands"), aland_islands_bb);

    BoundingBox albania_bb;
    albania_bb.latShift = 0.0;
    albania_bb.lonShift = 0.0;
    albania_bb.lowerLeft.lat = 39.625;
    albania_bb.lowerLeft.lon = 19.304;
    albania_bb.upperRight.lat = 42.688;
    albania_bb.upperRight.lon = 21.020;
    retn.insert(QLatin1String("Albania"), albania_bb);

    BoundingBox andorra_bb;
    andorra_bb.latShift = 0.0;
    andorra_bb.lonShift = 0.0;
    andorra_bb.lowerLeft.lat = 39.644;
    andorra_bb.lowerLeft.lon = 1.414;
    andorra_bb.upperRight.lat = 41.248;
    andorra_bb.upperRight.lon = 1.787;
    retn.insert(QLatin1String("Andorra"), andorra_bb);

    BoundingBox armenia_bb;
    armenia_bb.latShift = 0.0;
    armenia_bb.lonShift = 0.0;
    armenia_bb.lowerLeft.lat = 38.741;
    armenia_bb.lowerLeft.lon = 43.583;
    armenia_bb.upperRight.lat = 41.248;
    armenia_bb.upperRight.lon = 46.505;
    retn.insert(QLatin1String("Armenia"), armenia_bb);

    BoundingBox austria_bb;
    austria_bb.latShift = 0.0;
    austria_bb.lonShift = 0.0;
    austria_bb.lowerLeft.lat = 46.432;
    austria_bb.lowerLeft.lon = 9.480;
    austria_bb.upperRight.lat = 49.039;
    austria_bb.upperRight.lon = 16.980;
    retn.insert(QLatin1String("Austria"), austria_bb);

    BoundingBox azerbaijan_bb;
    azerbaijan_bb.latShift = 0.0;
    azerbaijan_bb.lonShift = 0.0;
    azerbaijan_bb.lowerLeft.lat = 38.2704;
    azerbaijan_bb.lowerLeft.lon = 44.794;
    azerbaijan_bb.upperRight.lat = 41.861;
    azerbaijan_bb.upperRight.lon = 50.393;
    retn.insert(QLatin1String("Azerbaijan"), azerbaijan_bb);

    BoundingBox belarus_bb;
    belarus_bb.latShift = 0.0;
    belarus_bb.lonShift = 0.0;
    belarus_bb.lowerLeft.lat = 51.320;
    belarus_bb.lowerLeft.lon = 23.199;
    belarus_bb.upperRight.lat = 56.1691;
    belarus_bb.upperRight.lon = 32.694;
    retn.insert(QLatin1String("Belarus"), belarus_bb);

    BoundingBox belgium_bb;
    belgium_bb.latShift = 0.0;
    belgium_bb.lonShift = 0.0;
    belgium_bb.lowerLeft.lat = 49.529;
    belgium_bb.lowerLeft.lon = 2.514;
    belgium_bb.upperRight.lat = 51.475;
    belgium_bb.upperRight.lon = 6.157;
    retn.insert(QLatin1String("Belgium"), belgium_bb);

    BoundingBox bosnia_and_herzegovina_bb;
    bosnia_and_herzegovina_bb.latShift = 0.0;
    bosnia_and_herzegovina_bb.lonShift = 0.0;
    bosnia_and_herzegovina_bb.lowerLeft.lat = 42.650;
    bosnia_and_herzegovina_bb.lowerLeft.lon = 15.750;
    bosnia_and_herzegovina_bb.upperRight.lat = 45.234;
    bosnia_and_herzegovina_bb.upperRight.lon = 19.600;
    retn.insert(QLatin1String("Bosnia_and_Herzegovina"), bosnia_and_herzegovina_bb);

    BoundingBox bulgaria_bb;
    bulgaria_bb.latShift = 0.0;
    bulgaria_bb.lonShift = 0.0;
    bulgaria_bb.lowerLeft.lat = 41.234;
    bulgaria_bb.lowerLeft.lon = 22.381;
    bulgaria_bb.upperRight.lat = 44.235;
    bulgaria_bb.upperRight.lon = 28.558;
    retn.insert(QLatin1String("Bulgaria"), bulgaria_bb);

    BoundingBox croatia_bb;
    croatia_bb.latShift = 0.0;
    croatia_bb.lonShift = 0.0;
    croatia_bb.lowerLeft.lat = 42.490;
    croatia_bb.lowerLeft.lon = 13.657;
    croatia_bb.upperRight.lat = 46.504;
    croatia_bb.upperRight.lon = 19.390;
    retn.insert(QLatin1String("Croatia"), croatia_bb);

    BoundingBox cyprus_bb;
    cyprus_bb.latShift = 0.0;
    cyprus_bb.lonShift = 0.0;
    cyprus_bb.lowerLeft.lat = 34.572;
    cyprus_bb.lowerLeft.lon = 32.257;
    cyprus_bb.upperRight.lat = 35.173;
    cyprus_bb.upperRight.lon = 34.005;
    retn.insert(QLatin1String("Cyprus"), cyprus_bb);

    BoundingBox czech_republic_bb;
    czech_republic_bb.latShift = 0.0;
    czech_republic_bb.lonShift = 0.0;
    czech_republic_bb.lowerLeft.lat = 48.555;
    czech_republic_bb.lowerLeft.lon = 12.240;
    czech_republic_bb.upperRight.lat = 51.117;
    czech_republic_bb.upperRight.lon = 18.853;
    retn.insert(QLatin1String("Czech_Republic"), czech_republic_bb);

    BoundingBox denmark_bb;
    denmark_bb.latShift = 0.0;
    denmark_bb.lonShift = 0.0;
    denmark_bb.lowerLeft.lat = 54.800;
    denmark_bb.lowerLeft.lon = 8.090;
    denmark_bb.upperRight.lat = 57.7300;
    denmark_bb.upperRight.lon = 12.690;
    retn.insert(QLatin1String("Denmark"), denmark_bb);

    BoundingBox estonia_bb;
    estonia_bb.latShift = 0.0;
    estonia_bb.lonShift = 0.0;
    estonia_bb.lowerLeft.lat = 57.475;
    estonia_bb.lowerLeft.lon = 23.340;
    estonia_bb.upperRight.lat = 59.611;
    estonia_bb.upperRight.lon = 28.132;
    retn.insert(QLatin1String("Estonia"), estonia_bb);

    BoundingBox faroe_islands_bb;
    faroe_islands_bb.latShift = 0.0;
    faroe_islands_bb.lonShift = 0.0;
    faroe_islands_bb.lowerLeft.lat = 61.395;
    faroe_islands_bb.lowerLeft.lon = -7.681;
    faroe_islands_bb.upperRight.lat = 62.401;
    faroe_islands_bb.upperRight.lon = -6.259;
    retn.insert(QLatin1String("Faroe_Islands"), faroe_islands_bb);

    BoundingBox finland_bb;
    finland_bb.latShift = 0.0;
    finland_bb.lonShift = 0.0;
    finland_bb.lowerLeft.lat = 59.45;
    finland_bb.lowerLeft.lon = 18.0;
    finland_bb.upperRight.lat = 70.083;
    finland_bb.upperRight.lon = 33.35;
    retn.insert(QLatin1String("Finland"), finland_bb);

    BoundingBox france_bb;
    france_bb.latShift = 0.0;
    france_bb.lonShift = 0.0;
    france_bb.lowerLeft.lat = 2.0534;
    france_bb.lowerLeft.lon = -54.5248;
    france_bb.upperRight.lat = 51.149;
    france_bb.upperRight.lon = 9.560;
    retn.insert(QLatin1String("France"), france_bb);

    BoundingBox georgia_bb;
    georgia_bb.latShift = 0.0;
    georgia_bb.lonShift = 0.0;
    georgia_bb.lowerLeft.lat = 41.064;
    georgia_bb.lowerLeft.lon = 39.955;
    georgia_bb.upperRight.lat = 43.553;
    georgia_bb.upperRight.lon = 46.648;
    retn.insert(QLatin1String("Georgia"), georgia_bb);

    BoundingBox germany_bb;
    germany_bb.latShift = 0.0;
    germany_bb.lonShift = 0.0;
    germany_bb.lowerLeft.lat = 47.302;
    germany_bb.lowerLeft.lon = 5.989;
    germany_bb.upperRight.lat = 54.983;
    germany_bb.upperRight.lon = 15.017;
    retn.insert(QLatin1String("Germany"), germany_bb);

    BoundingBox gibraltar_bb;
    gibraltar_bb.latShift = 0.0;
    gibraltar_bb.lonShift = 0.0;
    gibraltar_bb.lowerLeft.lat = 36.108;
    gibraltar_bb.lowerLeft.lon = -5.358;
    gibraltar_bb.upperRight.lat = 36.156;
    gibraltar_bb.upperRight.lon = -5.339;
    retn.insert(QLatin1String("Gibraltar"), gibraltar_bb);

    BoundingBox greece_bb;
    greece_bb.latShift = 0.0;
    greece_bb.lonShift = 0.0;
    greece_bb.lowerLeft.lat = 34.920;
    greece_bb.lowerLeft.lon = 20.150;
    greece_bb.upperRight.lat = 41.827;
    greece_bb.upperRight.lon = 26.604;
    retn.insert(QLatin1String("Greece"), greece_bb);

    BoundingBox guernsey_bb;
    guernsey_bb.latShift = 0.0;
    guernsey_bb.lonShift = 0.0;
    guernsey_bb.lowerLeft.lat = 49.406;
    guernsey_bb.lowerLeft.lon = -2.675;
    guernsey_bb.upperRight.lat = 49.739;
    guernsey_bb.upperRight.lon = -2.164;
    retn.insert(QLatin1String("Guernsey"), guernsey_bb);

    BoundingBox hungary_bb;
    hungary_bb.latShift = 0.0;
    hungary_bb.lonShift = 0.0;
    hungary_bb.lowerLeft.lat = 45.759;
    hungary_bb.lowerLeft.lon = 16.202;
    hungary_bb.upperRight.lat = 48.624;
    hungary_bb.upperRight.lon = 22.711;
    retn.insert(QLatin1String("Hungary"), hungary_bb);

    BoundingBox iceland_bb;
    iceland_bb.latShift = 0.0;
    iceland_bb.lonShift = 0.0;
    iceland_bb.lowerLeft.lat = 63.496;
    iceland_bb.lowerLeft.lon = -24.326;
    iceland_bb.upperRight.lat = 66.526;
    iceland_bb.upperRight.lon = -13.609;
    retn.insert(QLatin1String("Iceland"), iceland_bb);

    BoundingBox ireland_bb;
    ireland_bb.latShift = 0.0;
    ireland_bb.lonShift = 0.0;
    ireland_bb.lowerLeft.lat = 51.669;
    ireland_bb.lowerLeft.lon = -9.977;
    ireland_bb.upperRight.lat = 55.132;
    ireland_bb.upperRight.lon = -6.030;
    retn.insert(QLatin1String("Ireland"), ireland_bb);

    BoundingBox isle_of_man_bb;
    isle_of_man_bb.latShift = 0.0;
    isle_of_man_bb.lonShift = 0.0;
    isle_of_man_bb.lowerLeft.lat = 54.045;
    isle_of_man_bb.lowerLeft.lon = -4.830;
    isle_of_man_bb.upperRight.lat = 54.419;
    isle_of_man_bb.upperRight.lon = -4.310;
    retn.insert(QLatin1String("Isle_of_Man"), isle_of_man_bb);

    BoundingBox italy_bb;
    italy_bb.latShift = 0.0;
    italy_bb.lonShift = 0.0;
    italy_bb.lowerLeft.lat = 36.620;
    italy_bb.lowerLeft.lon = 6.745;
    italy_bb.upperRight.lat = 47.115;
    italy_bb.upperRight.lon = 18.480;
    retn.insert(QLatin1String("Italy"), italy_bb);

    BoundingBox jersey_bb;
    jersey_bb.latShift = 0.0;
    jersey_bb.lonShift = 0.0;
    jersey_bb.lowerLeft.lat = 49.162;
    jersey_bb.lowerLeft.lon = -2.255;
    jersey_bb.upperRight.lat = 49.262;
    jersey_bb.upperRight.lon = -2.011;
    retn.insert(QLatin1String("Jersey"), jersey_bb);

    BoundingBox kazakhstan_bb;
    kazakhstan_bb.latShift = 0.0;
    kazakhstan_bb.lonShift = 0.0;
    kazakhstan_bb.lowerLeft.lat = 40.663;
    kazakhstan_bb.lowerLeft.lon = 46.466;
    kazakhstan_bb.upperRight.lat = 55.385;
    kazakhstan_bb.upperRight.lon = 87.360;
    retn.insert(QLatin1String("Kazakhstan"), kazakhstan_bb);

    BoundingBox kosovo_bb;
    kosovo_bb.latShift = 0.0;
    kosovo_bb.lonShift = 0.0;
    kosovo_bb.lowerLeft.lat = 42.111;
    kosovo_bb.lowerLeft.lon = 20.787;
    kosovo_bb.upperRight.lat = 43.153;
    kosovo_bb.upperRight.lon = 21.514;
    retn.insert(QLatin1String("Kosovo"), kosovo_bb);

    BoundingBox latvia_bb;
    latvia_bb.latShift = 0.0;
    latvia_bb.lonShift = 0.0;
    latvia_bb.lowerLeft.lat = 55.615;
    latvia_bb.lowerLeft.lon = 21.056;
    latvia_bb.upperRight.lat = 57.970;
    latvia_bb.upperRight.lon = 28.176;
    retn.insert(QLatin1String("Latvia"), latvia_bb);

    BoundingBox liechtenstein_bb;
    liechtenstein_bb.latShift = 0.0;
    liechtenstein_bb.lonShift = 0.0;
    liechtenstein_bb.lowerLeft.lat = 47.048;
    liechtenstein_bb.lowerLeft.lon = 9.472;
    liechtenstein_bb.upperRight.lat = 47.270;
    liechtenstein_bb.upperRight.lon = 9.636;
    retn.insert(QLatin1String("Liechtenstein"), liechtenstein_bb);

    BoundingBox lithuania_bb;
    lithuania_bb.latShift = 0.0;
    lithuania_bb.lonShift = 0.0;
    lithuania_bb.lowerLeft.lat = 53.906;
    lithuania_bb.lowerLeft.lon = 21.056;
    lithuania_bb.upperRight.lat = 56.373;
    lithuania_bb.upperRight.lon = 26.588;
    retn.insert(QLatin1String("Lithuania"), lithuania_bb);

    BoundingBox luxembourg_bb;
    luxembourg_bb.latShift = 0.0;
    luxembourg_bb.lonShift = 0.0;
    luxembourg_bb.lowerLeft.lat = 49.443;
    luxembourg_bb.lowerLeft.lon = 5.674;
    luxembourg_bb.upperRight.lat = 50.128;
    luxembourg_bb.upperRight.lon = 6.243;
    retn.insert(QLatin1String("Luxembourg"), luxembourg_bb);

    BoundingBox macedonia_bb;
    macedonia_bb.latShift = 0.0;
    macedonia_bb.lonShift = 0.0;
    macedonia_bb.lowerLeft.lat = 40.843;
    macedonia_bb.lowerLeft.lon = 20.463;
    macedonia_bb.upperRight.lat = 42.320;
    macedonia_bb.upperRight.lon = 22.952;
    retn.insert(QLatin1String("Macedonia"), macedonia_bb);

    BoundingBox malta_bb;
    malta_bb.latShift = 0.0;
    malta_bb.lonShift = 0.0;
    malta_bb.lowerLeft.lat = 35.786;
    malta_bb.lowerLeft.lon = 14.183;
    malta_bb.upperRight.lat = 36.082;
    malta_bb.upperRight.lon = 14.577;
    retn.insert(QLatin1String("Malta"), malta_bb);

    BoundingBox moldova_bb;
    moldova_bb.latShift = 0.0;
    moldova_bb.lonShift = 0.0;
    moldova_bb.lowerLeft.lat = 45.488;
    moldova_bb.lowerLeft.lon = 26.619;
    moldova_bb.upperRight.lat = 48.497;
    moldova_bb.upperRight.lon = 30.025;
    retn.insert(QLatin1String("Moldova"), moldova_bb);

    BoundingBox monaco_bb;
    monaco_bb.latShift = 0.0;
    monaco_bb.lonShift = 0.0;
    monaco_bb.lowerLeft.lat = 43.725;
    monaco_bb.lowerLeft.lon = 7.409;
    monaco_bb.upperRight.lat = 43.752;
    monaco_bb.upperRight.lon = 7.439;
    retn.insert(QLatin1String("Monaco"), monaco_bb);

    BoundingBox montenegro_bb;
    montenegro_bb.latShift = 0.0;
    montenegro_bb.lonShift = 0.0;
    montenegro_bb.lowerLeft.lat = 41.878;
    montenegro_bb.lowerLeft.lon = 18.45;
    montenegro_bb.upperRight.lat = 43.524;
    montenegro_bb.upperRight.lon = 20.340;
    retn.insert(QLatin1String("Montenegro"), montenegro_bb);

    BoundingBox netherlands_bb;
    netherlands_bb.latShift = 0.0;
    netherlands_bb.lonShift = 0.0;
    netherlands_bb.lowerLeft.lat = 50.804;
    netherlands_bb.lowerLeft.lon = 3.315;
    netherlands_bb.upperRight.lat = 53.510;
    netherlands_bb.upperRight.lon = 7.092;
    retn.insert(QLatin1String("Netherlands"), netherlands_bb);

    BoundingBox norway_bb;
    norway_bb.latShift = 0.0;
    norway_bb.lonShift = 0.0;
    norway_bb.lowerLeft.lat = 58.079;
    norway_bb.lowerLeft.lon = 4.992;
    norway_bb.upperRight.lat = 80.657;
    norway_bb.upperRight.lon = 31.293;
    retn.insert(QLatin1String("Norway"), norway_bb);

    BoundingBox poland_bb;
    poland_bb.latShift = 0.0;
    poland_bb.lonShift = 0.0;
    poland_bb.lowerLeft.lat = 49.027;
    poland_bb.lowerLeft.lon = 14.075;
    poland_bb.upperRight.lat = 54.851;
    poland_bb.upperRight.lon = 24.030;
    retn.insert(QLatin1String("Poland"), poland_bb);

    BoundingBox portugal_bb;
    portugal_bb.latShift = 0.0;
    portugal_bb.lonShift = 0.0;
    portugal_bb.lowerLeft.lat = 36.838;
    portugal_bb.lowerLeft.lon = -9.527;
    portugal_bb.upperRight.lat = 42.280;
    portugal_bb.upperRight.lon = -6.389;
    retn.insert(QLatin1String("Portugal"), portugal_bb);

    BoundingBox romania_bb;
    romania_bb.latShift = 0.0;
    romania_bb.lonShift = 0.0;
    romania_bb.lowerLeft.lat = 43.688;
    romania_bb.lowerLeft.lon = 20.220;
    romania_bb.upperRight.lat = 48.221;
    romania_bb.upperRight.lon = 29.637;
    retn.insert(QLatin1String("Romania"), romania_bb);

    BoundingBox san_marino_bb;
    san_marino_bb.latShift = 0.0;
    san_marino_bb.lonShift = 0.0;
    san_marino_bb.lowerLeft.lat = 43.893;
    san_marino_bb.lowerLeft.lon = 12.403;
    san_marino_bb.upperRight.lat = 43.992;
    san_marino_bb.upperRight.lon = 12.517;
    retn.insert(QLatin1String("San_Marino"), san_marino_bb);

    BoundingBox serbia_bb;
    serbia_bb.latShift = 0.0;
    serbia_bb.lonShift = 0.0;
    serbia_bb.lowerLeft.lat = 42.245;
    serbia_bb.lowerLeft.lon = 18.830;
    serbia_bb.upperRight.lat = 46.171;
    serbia_bb.upperRight.lon = 22.986;
    retn.insert(QLatin1String("Serbia"), serbia_bb);

    BoundingBox slovakia_bb;
    slovakia_bb.latShift = 0.0;
    slovakia_bb.lonShift = 0.0;
    slovakia_bb.lowerLeft.lat = 47.758;
    slovakia_bb.lowerLeft.lon = 16.880;
    slovakia_bb.upperRight.lat = 49.571;
    slovakia_bb.upperRight.lon = 22.558;
    retn.insert(QLatin1String("Slovakia"), slovakia_bb);

    BoundingBox slovenia_bb;
    slovenia_bb.latShift = 0.0;
    slovenia_bb.lonShift = 0.0;
    slovenia_bb.lowerLeft.lat = 45.452;
    slovenia_bb.lowerLeft.lon = 13.698;
    slovenia_bb.upperRight.lat = 46.852;
    slovenia_bb.upperRight.lon = 16.565;
    retn.insert(QLatin1String("Slovenia"), slovenia_bb);

    BoundingBox spain_bb;
    spain_bb.latShift = 0.0;
    spain_bb.lonShift = 0.0;
    spain_bb.lowerLeft.lat = 35.947;
    spain_bb.lowerLeft.lon = -9.393;
    spain_bb.upperRight.lat = 43.748;
    spain_bb.upperRight.lon = 3.039;
    retn.insert(QLatin1String("Spain"), spain_bb);

    BoundingBox sweden_bb;
    sweden_bb.latShift = 0.0;
    sweden_bb.lonShift = 0.0;
    sweden_bb.lowerLeft.lat = 55.362;
    sweden_bb.lowerLeft.lon = 11.027;
    sweden_bb.upperRight.lat = 69.106;
    sweden_bb.upperRight.lon = 23.903;
    retn.insert(QLatin1String("Sweden"), sweden_bb);

    BoundingBox switzerland_bb;
    switzerland_bb.latShift = 0.0;
    switzerland_bb.lonShift = 0.0;
    switzerland_bb.lowerLeft.lat = 45.777;
    switzerland_bb.lowerLeft.lon = 6.023;
    switzerland_bb.upperRight.lat = 47.831;
    switzerland_bb.upperRight.lon = 10.443;
    retn.insert(QLatin1String("Switzerland"), switzerland_bb);

    BoundingBox ukraine_bb;
    ukraine_bb.latShift = 0.0;
    ukraine_bb.lonShift = 0.0;
    ukraine_bb.lowerLeft.lat = 44.361;
    ukraine_bb.lowerLeft.lon = 22.057;
    ukraine_bb.upperRight.lat = 52.335;
    ukraine_bb.upperRight.lon = 40.081;
    retn.insert(QLatin1String("Ukraine"), ukraine_bb);

    BoundingBox united_kingdom_bb;
    united_kingdom_bb.latShift = 0.0;
    united_kingdom_bb.lonShift = 0.0;
    united_kingdom_bb.lowerLeft.lat = 49.960;
    united_kingdom_bb.lowerLeft.lon = -7.572;
    united_kingdom_bb.upperRight.lat = 58.635;
    united_kingdom_bb.upperRight.lon = 1.681;
    retn.insert(QLatin1String("United_Kingdom"), united_kingdom_bb);

    BoundingBox australia_bb;
    australia_bb.latShift = 0.0;
    australia_bb.lonShift = 0.0;
    australia_bb.lowerLeft.lat = -55.05;
    australia_bb.lowerLeft.lon = 112.467;
    australia_bb.upperRight.lat = -9.133;
    australia_bb.upperRight.lon = 168.0;
    retn.insert(QLatin1String("Australia"), australia_bb);

    return retn;
}

QMap<QString, QVector<BoundingBox> > regionBoundingBoxes()
{
    QMap<QString, QVector<BoundingBox> > retn;
    QMap<QString, BoundingBox> cbboxes(countryBoundingBoxes());

    // Devel is a special region for development/testing purposes.
    // Devel is not able to be represented by a single bounding box.
    // Instead, we hardcode its contents to include the bounding boxes
    // for Finland, Australia and India.
    QVector<BoundingBox> devel;
    devel << cbboxes.value(QLatin1String("Finland"))
          << cbboxes.value(QLatin1String("Australia"))
          << cbboxes.value(QLatin1String("India"));
    retn.insert(QLatin1String("Devel"), devel);

    return retn;
}

struct ParseLineResult {
    bool withinBBox;
    MlsdbUniqueCellId uniqueCellId;
    MlsdbCoords loc;
};
ParseLineResult parseLineAndTest(const QByteArray &line, const QVector<BoundingBox> &boundingBoxes)
{
    ParseLineResult result;
    result.withinBBox = false;

    // radio,mcc,net,area,cell,unit,lon,lat,range,samples,changeable,created,updated,averageSignal
    QList<QByteArray> fields = line.split(',');
    // grab the type of cell (LTE, GSM, UMTS, etc)
    QString cellTypeStr = QString::fromLatin1(fields[0]);
    MlsdbCellType cellType = MLSDB_CELL_TYPE_LTE;
    if (cellTypeStr.compare(QLatin1String("LTE"), Qt::CaseInsensitive) == 0) {
        cellType = MLSDB_CELL_TYPE_LTE;
    } else if (cellTypeStr.compare(QLatin1String("GSM"), Qt::CaseInsensitive) == 0) {
        cellType = MLSDB_CELL_TYPE_GSM;
    } else if (cellTypeStr.compare(QLatin1String("UMTS"), Qt::CaseInsensitive) == 0) {
        cellType = MLSDB_CELL_TYPE_UMTS;
    } else {
        cellType = MLSDB_CELL_TYPE_OTHER;
    }
    // parse mcc and mnc fields
    quint16 mcc = QString::fromLatin1(fields[1]).isEmpty() ? 0 : QString::fromLatin1(fields[1]).toUInt();
    quint16 mnc = QString::fromLatin1(fields[2]).isEmpty() ? 0 : QString::fromLatin1(fields[2]).toUInt();
    // check to see that there is a cellId associated.  not the case for some UMTS cells.
    quint32 cellId = QString::fromLatin1(fields[4]).isEmpty() ? 0 : QString::fromLatin1(fields[4]).toUInt();
    quint32 locationCode = QString::fromLatin1(fields[3]).isEmpty() ? 0 : QString::fromLatin1(fields[3]).toUInt();
    if (cellId > 0) {
        // build the cell location.
        result.uniqueCellId = MlsdbUniqueCellId(cellType, cellId, locationCode, mcc, mnc);
        result.loc.lat = QString::fromLatin1(fields[7]).toDouble();
        result.loc.lon = QString::fromLatin1(fields[6]).toDouble();
        // check to see if it's within our bounding boxes
        Q_FOREACH (const BoundingBox &bbox, boundingBoxes) {
            if (bbox.contains(result.loc)) {
                result.withinBBox = true;
                return result;
            }
        }
    }
    return result;
}

QMap<MlsdbUniqueCellId, MlsdbCoords> siftMlsCsvData(const QString &mlscsv, const QVector<BoundingBox> &boundingBoxes)
{
    QMap<MlsdbUniqueCellId, MlsdbCoords> cellIdToMlsdbCoords;

    // read the csv file line by line, check whether it belongs in the map, insert or discard.
    QFile file(mlscsv);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        fprintf(stderr, "Failed to open Mozilla Location Services data .csv file for reading!\n");
        return cellIdToMlsdbCoords;
    }

    fprintf(stdout, "Reading data from file and caching cell locations which are within the bounding boxes...\n");
    quint32 readlines = 0, insertedcells = 0, progresscount = 0;
#if USE_CONCURRENT
    int currentJobs = THREADCOUNT-1;
#if USE_STD_CONCURRENT
    std::vector<std::future<ParseLineResult> > results;
#else
    QList<QFuture<ParseLineResult> > results;
#endif // USE_STD_CONCURRENT
#endif // USE_CONCURRENT
    fprintf(stdout, "Progress: %d lines read, %d cell locations inserted", readlines, insertedcells);
    while (true) {
        if (file.atEnd()) break;
#if USE_CONCURRENT
        currentJobs = THREADCOUNT-1;
        results.clear();
        while (!file.atEnd() && currentJobs) {
            currentJobs--;
            const QByteArray line = file.readLine();
            readlines++;
#if USE_STD_CONCURRENT
            results.push_back(std::async(parseLineAndTest, line, boundingBoxes));
#else
            results.append(QtConcurrent::run(parseLineAndTest, line, boundingBoxes));
#endif // USE_STD_CONCURRENT
        }

#if USE_STD_CONCURRENT
        for (auto &result : results) {
            ParseLineResult r = result.get();
#else
        while (results.size()) {
            result.waitForFinished();
            ParseLineResult r = result.result();
#endif // USE_STD_CONCURRENT
#else  // single-threaded only
        {
            QByteArray line = file.readLine();
            readlines++;
            ParseLineResult r = parseLineAndTest(line, boundingBoxes);
#endif
            if (r.withinBBox) {
                insertedcells++;
                cellIdToMlsdbCoords.insert(r.uniqueCellId, r.loc);
            }
            progresscount++;
        }

        if (progresscount >= 10000) {
            progresscount = 0;
            fprintf(stdout, "\33[2K\rProgress: %d lines read, %d cell locations inserted", readlines, insertedcells); // line overwrite
            fflush(stdout);
        }
    }

    fprintf(stdout, "\nFinished reading data: %d lines read, %d cell locations inserted\n", readlines, insertedcells);
    return cellIdToMlsdbCoords;
}

int writeMlsdbData(const QMap<MlsdbUniqueCellId, MlsdbCoords> &cellIdToLocation)
{
    if (cellIdToLocation.isEmpty()) {
        fprintf(stderr, "No cell locations found which match the required bounding boxes!\n");
        return 1;
    }

    // split the complete cellIdToLocation dictionary into per-location-code-first-digit sub-dictionaries
    QMap<QChar, QMap<MlsdbUniqueCellId, MlsdbCoords> > perLcfdCellIdToLocation;
    for (QMap<MlsdbUniqueCellId, MlsdbCoords>::const_iterator it = cellIdToLocation.constBegin();
         it != cellIdToLocation.constEnd(); it++) {
        perLcfdCellIdToLocation[QString::number(it.key().locationCode()).at(0)].insert(it.key(), it.value());
    }

    // write each sub-dictionary into a first-digit-of-location-code-specific directory.
    QDir dir;
    for (QMap<QChar, QMap<MlsdbUniqueCellId, MlsdbCoords> >::const_iterator it = perLcfdCellIdToLocation.constBegin();
         it != perLcfdCellIdToLocation.constEnd(); ++it) {
        // create the directory
        dir.mkpath(QStringLiteral("./%1").arg(it.key()));
        // write the data file
        const QString fileName(QStringLiteral("./%1/mlsdb.data").arg(it.key()));
        fprintf(stdout, "Writing data (%d entries) to mlsdb.data file: %s\n", it.value().size(), fileName.toStdString().c_str());
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);
        out << (quint32)0xc710cdb; // magic cell-tower location db number
        out << (qint32)3;          // data file version number
        out.setVersion(QDataStream::Qt_5_0);
        out << it.value();
    }

    fprintf(stdout, "Done!\n");
    return 0; // success
}

int queryCellLocation(quint32 locationAreaCode, quint32 cellId, quint16 mcc, quint16 mnc, const QString &mlsdbdata)
{
    if (cellId == 0) {
        fprintf(stderr, "Invalid cellId specified!\n");
        return -1;
    }

    if (!QFile::exists(mlsdbdata)) {
        fprintf(stderr, "geoclue-mlsdb data file does not exist: %s\n", mlsdbdata.toStdString().c_str());
        return 1;
    }

    fprintf(stdout, "Reading data from mlsdb.data file...\n");
    QFile file(mlsdbdata);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    quint32 magic = 0, expectedMagic = (quint32)0xc710cdb;
    in >> magic;
    if (magic != 0xc710cdb) {
        fprintf(stderr, "geoclue-mlsdb data file format unknown: %d (expect %d)\n", magic, expectedMagic);
        return 1;
    }
    qint32 version;
    in >> version;
    if (version != 3) {
        fprintf(stderr, "geoclue-mlsdb data file version unknown: %d\n", version);
        return 1;
    }
    QMap<MlsdbUniqueCellId, MlsdbCoords> uniqueCellIdToLocation;
    in >> uniqueCellIdToLocation;
    if (uniqueCellIdToLocation.isEmpty()) {
        fprintf(stderr, "geoclue-mlsdb data file contained no cell locations!\n");
        return 1;
    }

    fprintf(stdout, "Searching for %d within data...\n", cellId);
    MlsdbUniqueCellId lteCellId = MlsdbUniqueCellId(MLSDB_CELL_TYPE_LTE, cellId, locationAreaCode, mcc, mnc);
    MlsdbUniqueCellId gsmCellId = MlsdbUniqueCellId(MLSDB_CELL_TYPE_GSM, cellId, locationAreaCode, mcc, mnc);
    MlsdbUniqueCellId umtsCellId = MlsdbUniqueCellId(MLSDB_CELL_TYPE_UMTS, cellId, locationAreaCode, mcc, mnc);
    if (!uniqueCellIdToLocation.contains(lteCellId) && !uniqueCellIdToLocation.contains(gsmCellId) && !uniqueCellIdToLocation.contains(umtsCellId)) {
        fprintf(stderr, "geoclue-mlsdb data file does not contain location of cell with id: %d in LAC: %d with MCC: %d, MNC: %d\n", cellId, locationAreaCode, mcc, mnc);
        return 1;
    }

    if (uniqueCellIdToLocation.contains(lteCellId)) {
        MlsdbCoords cellLocation = uniqueCellIdToLocation.value(lteCellId);
        fprintf(stdout, "LTE cell with id %d is at lat,lon: %f, %f\n", lteCellId.cellId(), cellLocation.lat, cellLocation.lon);
    }

    if (uniqueCellIdToLocation.contains(gsmCellId)) {
        MlsdbCoords cellLocation = uniqueCellIdToLocation.value(gsmCellId);
        fprintf(stdout, "GSM cell with id %d is at lat,lon: %f, %f\n", gsmCellId.cellId(), cellLocation.lat, cellLocation.lon);
    }

    if (uniqueCellIdToLocation.contains(umtsCellId)) {
        MlsdbCoords cellLocation = uniqueCellIdToLocation.value(umtsCellId);
        fprintf(stdout, "UMTS cell with id %d is at lat,lon: %f, %f\n", umtsCellId.cellId(), cellLocation.lat, cellLocation.lon);
    }

    return 0; // success
}

int generateCountryDb(const QString &country, const QString &mlscsv)
{
    if (!QFile::exists(mlscsv)) {
        fprintf(stderr, "Mozilla Location Services .csv data file does not exist: %s\n", mlscsv.toStdString().c_str());
        return 1;
    }

    QMap<QString, BoundingBox> cbb = countryBoundingBoxes();
    if (!cbb.contains(country)) {
        fprintf(stderr, "Country bounding box not known: %s.  Note: case sensitive!\n", country.toStdString().c_str());
        return 1;
    }

    return writeMlsdbData(siftMlsCsvData(mlscsv, QVector<BoundingBox>() << cbb.value(country)));
}

int generateRegionDb(const QString &region, const QString &mlscsv)
{
    if (!QFile::exists(mlscsv)) {
        fprintf(stderr, "Mozilla Location Services .csv data file does not exist: %s\n", mlscsv.toStdString().c_str());
        return 1;
    }

    QMap<QString, QVector<BoundingBox> > rbb = regionBoundingBoxes();
    if (!rbb.contains(region)) {
        fprintf(stderr, "Region bounding box not known: %s.  Note: case sensitive!\n", region.toStdString().c_str());
        return 1;
    }

    return writeMlsdbData(siftMlsCsvData(mlscsv, rbb.value(region)));
}

void printGenericHelp()
{
    fprintf(stdout, "geoclue-mlsdb-tool is used to generate a datastructure containing"
                    " country- or region-specific GSM/UMTS/LTE cell location information.\n");
    fprintf(stdout, "Usage:\n\tgeoclue-mlsdb-tool --help [country|region]\n"
                    "\tgeoclue-mlsdb-tool -c <country> mls.csv\n"
                    "\tgeoclue-mlsdb-tool -r <region> mls.csv\n"
                    "\tgeoclue-mlsdb-tool --query <locationId> <cellId> <mcc> <mnc> mlsdb.data\n");
    fprintf(stdout, "For more information about valid country and region arguments,"
                    " run `geoclue-mlsdb-tool --help country` or `geoclue-mlsdb-tool --help region`.\n");
}

void printCountryHelp()
{
    fprintf(stdout, "Running `geoclue-mlsdb-tool -c <country> mls.csv` will generate an output"
                    " file `mlsdb.data` which contains a mapping from (uint32) cell id"
                    " to (double,double) latitude,longitude for all cells known"
                    " in the mls.csv within the bounding-box for that country.\n");
    fprintf(stdout, "Valid countries are:\n");
    fprintf(stdout, "\tNAME            \tLowerLeft(lat,lon)\tUpperRight(lat,lon)\n");
    const QMap<QString, BoundingBox> cbb(countryBoundingBoxes());
    Q_FOREACH (const QString &c, cbb.keys()) {
        const BoundingBox &bbox(cbb[c]);
        if (bbox.latShift == 0.0 && bbox.lonShift == 0.0) {
            fprintf(stdout, "\t%16s\t%f,%f\t%f,%f\n",
                    c.toStdString().c_str(),
                    bbox.lowerLeft.lat, bbox.lowerLeft.lon,
                    bbox.upperRight.lat, bbox.upperRight.lon);
        } else {
            fprintf(stdout, "\t%16s\t(complex bbox - crosses meridian or pole)\n",
                    c.toStdString().c_str());
        }
    }
}

void printRegionHelp()
{
    fprintf(stdout, "Running `geoclue-mlsdb-tool -r <region> mls.csv` will generate an output"
                    " file `mlsdb.data` which contains a mapping from (uint32) cell id"
                    " to (double,double) latitude,longitude for all cells known"
                    " in the mls.csv within the bounding-box for that region.\n"
                    "One special region is the `Devel` region which contains just"
                    " Finland, Australia and India.\n");
    fprintf(stdout, "Valid regions are:\n");
    const QMap<QString, QVector<BoundingBox> > rbb(regionBoundingBoxes());
    Q_FOREACH (const QString &r, rbb.keys()) {
        fprintf(stdout, "\t%s\n", r.toStdString().c_str());
    }
}

void printUsageError()
{
    fprintf(stderr, "usage:\n"
                    "\tgeoclue-mlsdb-tool --help [country|region]\n"
                    "\tgeoclue-mlsdb-tool -c <country> mls.csv\n"
                    "\tgeoclue-mlsdb-tool -r <region> mls.csv\n"
                    "\tgeoclue-mlsdb-tool --query <locationId> <cellId> <mcc> <mnc> mlsdb.data\n");
}

void detectDuplicates(const QString &mlscsv)
{
    QMultiMap<MlsdbUniqueCellId, MlsdbCoords> coords;
    const BoundingBox &bbox(countryBoundingBoxes().value(QStringLiteral("India")));

    // read the csv file line by line, check whether it belongs in the map, insert or discard.
    QFile file(mlscsv);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        fprintf(stderr, "Failed to open Mozilla Location Services data .csv file for reading!\n");
        return;
    }
    quint32 readlines = 0, progresscount = 0, insertedcells = 0;
    while (true) {
        if (file.atEnd()) break;
        QByteArray line = file.readLine();
        readlines++;
        ParseLineResult r = parseLineAndTest(line, QVector<BoundingBox>() << bbox);
        if (r.withinBBox) {
            insertedcells++;
            coords.insert(r.uniqueCellId, r.loc);
        }
        progresscount++;
        if (progresscount >= 10000) {
            progresscount = 0;
            fprintf(stdout, "\33[2K\rProgress: %d lines read, %d cell locations inserted", readlines, insertedcells); // line overwrite
            fflush(stdout);
        }
    }

    fprintf(stdout, "\nFinished: %d lines read, %d cell locations inserted\n", readlines, insertedcells);

    // determine if the locations are different
    Q_FOREACH (const MlsdbUniqueCellId &cellId, coords.keys()) {
        QList<MlsdbCoords> locs = coords.values(cellId);
        if (locs.size() > 1) {
            Q_FOREACH (const MlsdbCoords &loc, locs) {
                fprintf(stdout, "Have duplicate: type: %s, cellId: %d, locCode: %d, mcc: %d, mnc: %d, lat: %f, lon: %f\n",
                        stringForMlsdbCellType(cellId.cellType()).toStdString().c_str(),
                        cellId.cellId(), cellId.locationCode(), cellId.mcc(), cellId.mnc(),
                        loc.lat, loc.lon);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();

    if (args.length() <= 1) {
        printGenericHelp();
        return 0;
    }

    if (args[1] == QStringLiteral("help")
            || args[1] == QStringLiteral("-help")
            || args[1] == QStringLiteral("--help")
            || args[1] == QStringLiteral("-h")
            || args[1] == QStringLiteral("--h")) {
        if (args.length() == 2) {
            printGenericHelp();
        } else if (args.length() > 3) {
            printUsageError();
            return 1;
        } else {
            if (args[2] == QStringLiteral("country")) {
                printCountryHelp();
            } else if (args[2] == QStringLiteral("region")) {
                printRegionHelp();
            }
        }
        return 0;
    }

    bool countryRequest = args[1].compare(QStringLiteral("-c"), Qt::CaseInsensitive) == 0;
    bool regionRequest  = args[1].compare(QStringLiteral("-r"), Qt::CaseInsensitive) == 0;
    if (args.length() == 4 && (countryRequest || regionRequest)) {
        return countryRequest ? generateCountryDb(args[2], args[3]) : generateRegionDb(args[2], args[3]);
    } else if (args.length() == 7 && args[1].compare(QStringLiteral("--query"), Qt::CaseInsensitive) == 0) {
        return queryCellLocation(args[2].toUInt(), args[3].toUInt(), args[4].toUInt(), args[5].toUInt(), args[6]);
    }

    printUsageError();
    return 1;
}
