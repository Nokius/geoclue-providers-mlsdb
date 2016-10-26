TEMPLATE=aux

# Aland_Islands: generated with: geoclue-mlsdb-tool -c Aland_Islands MLS-full-cell-export-2016-10-26T000000.csv
aland_islands_data.files=ax/*
aland_islands_data.path=/usr/share/geoclue-provider-mlsdb/ax/

# Albania: generated with: geoclue-mlsdb-tool -c Albania MLS-full-cell-export-2016-10-26T000000.csv
albania_data.files=al/*
albania_data.path=/usr/share/geoclue-provider-mlsdb/al/

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
    $$india_data.files \
    $$australia_data.files \
    $$finland_data.files

INSTALLS += aland_islands_data albania_data india_data australia_data finland_data
