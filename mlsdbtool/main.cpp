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

// Europe

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
    retn.insert(QLatin1String("Austria"), austria_bb)

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
    retn.insert(QLatin1String("Bosnia and Herzegovina"), bosnia_and_herzegovina_bb);

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
    retn.insert(QLatin1String("Czech Republic"), czech_republic_bb);

    BoundingBox india_bb;
    india_bb.latShift = 0.0;
    india_bb.lonShift = 0.0;
    india_bb.lowerLeft.lat = 6.0;
    india_bb.lowerLeft.lon = 65.0;
    india_bb.upperRight.lat = 35.956;
    india_bb.upperRight.lon = 97.35;
    retn.insert(QLatin1String("India"), india_bb);

    BoundingBox australia_bb;
    australia_bb.latShift = 0.0;
    australia_bb.lonShift = 0.0;
    australia_bb.lowerLeft.lat = -55.05;
    australia_bb.lowerLeft.lon = 112.467;
    australia_bb.upperRight.lat = -9.133;
    australia_bb.upperRight.lon = 168.0;
    retn.insert(QLatin1String("Australia"), australia_bb);

    BoundingBox finland_bb;
    finland_bb.latShift = 0.0;
    finland_bb.lonShift = 0.0;
    finland_bb.lowerLeft.lat = 59.45;
    finland_bb.lowerLeft.lon = 18.0;
    finland_bb.upperRight.lat = 70.083;
    finland_bb.upperRight.lon = 33.35;
    retn.insert(QLatin1String("Finland"), finland_bb);

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
