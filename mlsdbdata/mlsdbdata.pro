TEMPLATE=aux

# Aland_Islands: generated with: geoclue-mlsdb-tool -c Aland_Islands MLS-full-cell-export-2016-10-26T000000.csv
aland_islands_data.files=ax/*
aland_islands_data.path=/usr/share/geoclue-provider-mlsdb/ax/

# Albania: generated with: geoclue-mlsdb-tool -c Albania MLS-full-cell-export-2016-10-26T000000.csv
albania_data.files=al/*
albania_data.path=/usr/share/geoclue-provider-mlsdb/al/

# Andorra: generated with: geoclue-mlsdb-tool -c Andorra MLS-full-cell-export-2016-10-26T000000.csv
andorra_data.files=ad/*
andorra_data.path=/usr/share/geoclue-provider-mlsdb/ad/

# Armenia: generated with: geoclue-mlsdb-tool -c Armenia MLS-full-cell-export-2016-10-26T000000.csv
armenia_data.files=am/*
armenia_data.path=/usr/share/geoclue-provider-mlsdb/am/

# Austria: generated with: geoclue-mlsdb-tool -c Austria MLS-full-cell-export-2016-10-26T000000.csv
austria_data.files=at/*
austria_data.path=/usr/share/geoclue-provider-mlsdb/at/

# Azerbaijan: generated with: geoclue-mlsdb-tool -c Azerbaijan MLS-full-cell-export-2016-10-26T000000.csv
azerbaijan_data.files=az/*
azerbaijan_data.path=/usr/share/geoclue-provider-mlsdb/az/

# Belarus: generated with: geoclue-mlsdb-tool -c Belarus MLS-full-cell-export-2016-10-26T000000.csv
belarus_data.files=by/*
belarus_data.path=/usr/share/geoclue-provider-mlsdb/by/

# Belgium: generated with: geoclue-mlsdb-tool -c Belgium MLS-full-cell-export-2016-10-26T000000.csv
belgium_data.files=be/*
belgium_data.path=/usr/share/geoclue-provider-mlsdb/be/

# India: generated with: geoclue-mlsdb-tool -c India MLS-full-cell-export-2016-03-14T000000.csv
india_data.files=in/*
india_data.path=/usr/share/geoclue-provider-mlsdb/in/

# Australia: generated with: geoclue-mlsdb-tool -c Australia MLS-full-cell-export-2016-03-14T000000.csv
australia_data.files=au/*
australia_data.path=/usr/share/geoclue-provider-mlsdb/au/

# Finland: generated with: geoclue-mlsdb-tool -c Finland MLS-full-cell-export-2016-03-14T000000.csv
finland_data.files=fi/*
finland_data.path=/usr/share/geoclue-provider-mlsdb/fi/

OTHER_FILES += \
    $$aland_islands_data.files \
    $$albania_data.files \
    $$andorra_data.files \
    $$armenia_data.files \
    $$austria_data.files \
    $$azerbaijan_data.files \
    $$belarus_data.files \
    $$belgium_data.files \
    $$india_data.files \
    $$australia_data.files \
    $$finland_data.files

INSTALLS += aland_islands_data albania_data andorra_data armenia_data austria_data azerbaijan_data belarus_data belgium_data india_data australia_data finland_data
