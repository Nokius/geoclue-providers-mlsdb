Name: geoclue-provider-mlsdb
Version: 0.0.12
Release: 1
Summary: Geoinformation Service from Mozilla Location Services Database Provider
Group: System/Libraries
URL: https://github.com/mer-hybris/geoclue-providers-mlsdb
License: LGPLv2.1
Source: %{name}-%{version}.tar.gz
BuildRequires: pkgconfig(Qt5Core)
BuildRequires: pkgconfig(Qt5DBus)
BuildRequires: pkgconfig(Qt5Network)
BuildRequires: pkgconfig(qofono-qt5)
BuildRequires: pkgconfig(qofonoext)
BuildRequires: pkgconfig(connman-qt5)
BuildRequires: pkgconfig(libsailfishkeyprovider)
BuildRequires: pkgconfig(qt5-boostable)
Requires: mapplauncherd-qt5
Requires: %{name}-agreements

%description
%{summary}.

%package agreements
Summary:  Mozilla Location Services privacy policy agreements
Group:    System/Libraries

%description agreements
%{summary}.

%package tool
Summary:   Cell id to location database tool for geoclue-provider-mlsdb
Group:     System/Application
Requires:  %{name} = %{version}

%description tool
%{summary}.

%package data-ax
Summary:   Cell id to location data (.ax)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-ax
%{summary}.

%package data-al
Summary:   Cell id to location data (.al)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-al
%{summary}.

%package data-ad
Summary:   Cell id to location data (.ad)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-ad
%{summary}.

%package data-am
Summary:   Cell id to location data (.am)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-am
%{summary}.

%package data-at
Summary:   Cell id to location data (.at)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-at
%{summary}.

%package data-az
Summary:   Cell id to location data (.az)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-az
%{summary}.

%package data-by
Summary:   Cell id to location data (.by)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-by
%{summary}.

%package data-be
Summary:   Cell id to location data (.be)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-be
%{summary}

%package data-ba
Summary:   Cell id to location data (.ba)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-ba
%{summary}.

%package data-bg
Summary:   Cell id to location data (.bg)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-bg
%{summary}.

%package data-hr
Summary:   Cell id to location data (.hr)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-hr
%{summary}.

%package data-cz
Summary:   Cell id to location data (.cz)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-cz
%{summary}.

%package data-cy
Summary:   Cell id to location data (.cy)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-cy
%{summary}.

%package data-dk
Summary:   Cell id to location data (.dk)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-dk
%{summary}.

%package data-ee
Summary:   Cell id to location data (.ee)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-ee
%{summary}.

%package data-fo
Summary:   Cell id to location data (.fo)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-fo
%{summary}.

%package data-fi
Summary:   Cell id to location data (.fi)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-fi
%{summary}.

%package data-fr
Summary:   Cell id to location data (.fr)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-fr
%{summary}.

%package data-ge
Summary:   Cell id to location data (.ge)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-ge
%{summary}.

%package data-de
Summary:   Cell id to location data (.de)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-de
%{summary}.

%package data-gi
Summary:   Cell id to location data (.gi)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-gi
%{summary}.

%package data-gr
Summary:   Cell id to location data (.gr)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-gr
%{summary}.

%package data-gg
Summary:   Cell id to location data (.gg)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-gg
%{summary}.

%package data-hu
Summary:   Cell id to location data (.hu)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-hu
%{summary}.

%package data-is
Summary:   Cell id to location data (.is)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-is
%{summary}.

%package data-ie
Summary:   Cell id to location data (.ie)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-ie
%{summary}.

%package data-im
Summary:   Cell id to location data (.im)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-im
%{summary}.

%package data-it
Summary:   Cell id to location data (.it)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-it
%{summary}.

%package data-je
Summary:   Cell id to location data (.je)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-je
%{summary}.

%package data-kz
Summary:   Cell id to location data (.kz)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-kz
%{summary}.

%package data-xk
Summary:   Cell id to location data (.xk)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-xk
%{summary}.

%package data-lv
Summary:   Cell id to location data (.lv)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-lv
%{summary}.

%package data-li
Summary:   Cell id to location data (.li)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-li
%{summary}.

%package data-lt
Summary:   Cell id to location data (.lt)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-lt
%{summary}.

%package data-lu
Summary:   Cell id to location data (.lu)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-lu
%{summary}.

%package data-mk
Summary:   Cell id to location data (.mk)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-mk
%{summary}.

%package data-mt
Summary:   Cell id to location data (.mt)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-mt
%{summary}.

%package data-md
Summary:   Cell id to location data (.md)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-md
%{summary}.

%package data-mc
Summary:   Cell id to location data (.mc)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-mc
%{summary}.

%package data-me
Summary:   Cell id to location data (.me)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-me
%{summary}.

%package data-nl
Summary:   Cell id to location data (.nl)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-nl
%{summary}.

%package data-no
Summary:   Cell id to location data (.no)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-no
%{summary}.

%package data-in
Summary:   Cell id to location data (.in)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-in
%{summary}.

%package data-au
Summary:   Cell id to location data (.au)
Group:     System/Data
Requires:  %{name} = %{version}

%description data-au
%{summary}.

%prep
%setup -q -n %{name}-%{version}


%build
qmake -qt=5 geoclue-providers-mlsdb.pro
make %{?_smp_mflags}


%install
make INSTALL_ROOT=%{buildroot} install

%files
%defattr(-,root,root,-)
%{_libexecdir}/geoclue-mlsdb
%{_datadir}/dbus-1/services/org.freedesktop.Geoclue.Providers.Mlsdb.service
%{_datadir}/geoclue-providers/geoclue-mlsdb.provider

%files agreements
%defattr(-,root,root,-)
%dir %{_datadir}/geoclue-provider-mlsdb/agreements
%{_datadir}/geoclue-provider-mlsdb/agreements/mls_consent_en_GB.txt


%files tool
%defattr(-,root,root,-)
%{_bindir}/geoclue-mlsdb-tool

%files data-ax
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/ax/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ax/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ax/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ax/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ax/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ax/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ax/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ax/9/mlsdb.data

%files data-al
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/al/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/al/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/al/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/al/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/al/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/al/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/al/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/al/9/mlsdb.data

%files data-ad
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/ad/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ad/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ad/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ad/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ad/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ad/8/mlsdb.data

%files data-am
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/am/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/am/9/mlsdb.data

%files data-at
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/at/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/at/9/mlsdb.data

%files data-az
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/az/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/az/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/az/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/az/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/az/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/az/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/az/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/az/8/mlsdb.data

%files data-by
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/by/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/by/9/mlsdb.data

%files data-be
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/be/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/be/9/mlsdb.data

%files data-ba
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/ba/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ba/9/mlsdb.data

%files data-bg
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/bg/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/bg/9/mlsdb.data

%files data-hr
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/hr/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hr/9/mlsdb.data

%files data-cz
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/cz/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cz/9/mlsdb.data

%files data-cy
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/cy/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cy/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cy/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cy/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cy/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cy/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cy/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/cy/9/mlsdb.data

%files data-dk
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/dk/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/dk/9/mlsdb.data

%files data-ee
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/ee/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ee/9/mlsdb.data

%files data-fo
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/fo/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fo/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fo/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fo/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fo/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fo/9/mlsdb.data

%files data-fi
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/fi/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fi/9/mlsdb.data

%files data-fr
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/fr/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/fr/9/mlsdb.data

%files data-ge
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/ge/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ge/9/mlsdb.data

%files data-de
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/de/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/de/9/mlsdb.data

%files data-gi
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/gi/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gi/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gi/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gi/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gi/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gi/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gi/9/mlsdb.data


%files data-gr
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/gr/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gr/9/mlsdb.data

%files data-gg
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/gg/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gg/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gg/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gg/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gg/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gg/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gg/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/gg/9/mlsdb.data

%files data-hu
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/hu/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/hu/9/mlsdb.data

%files data-is
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/is/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/is/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/is/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/is/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/is/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/is/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/is/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/is/8/mlsdb.data

%files data-ie
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/ie/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/ie/9/mlsdb.data

%files data-im
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/im/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/im/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/im/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/im/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/im/8/mlsdb.data

%files data-it
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/it/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/it/9/mlsdb.data

%files data-je
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/je/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/je/9/mlsdb.data

%files data-kz
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/kz/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/kz/9/mlsdb.data

%files data-xk
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/xk/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/xk/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/xk/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/xk/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/xk/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/xk/7/mlsdb.data

%files data-lv
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/lv/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lv/9/mlsdb.data

%files data-li
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/li/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/li/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/li/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/li/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/li/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/li/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/li/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/li/9/mlsdb.data

%files data-lt
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/lt/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lt/9/mlsdb.data

%files data-lu
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/lu/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lu/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lu/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lu/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lu/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lu/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/lu/7/mlsdb.data

%files data-mk
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/mk/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mk/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mk/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mk/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mk/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mk/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mk/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mk/9/mlsdb.data

%files data-mt
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/mt/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mt/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mt/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mt/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mt/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mt/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mt/9/mlsdb.data

%files data-md
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/md/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/md/9/mlsdb.data

%files data-mc
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/mc/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mc/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mc/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mc/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mc/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/mc/9/mlsdb.data

%files data-me
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/me/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/me/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/me/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/me/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/me/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/me/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/me/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/me/9/mlsdb.data

%files data-nl
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/nl/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/nl/9/mlsdb.data

%files data-no
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/no/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/no/9/mlsdb.data

%files data-in
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/in/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/in/9/mlsdb.data

%files data-au
%defattr(-,root,root,-)
%{_datadir}/geoclue-provider-mlsdb/au/1/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/2/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/3/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/4/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/5/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/6/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/7/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/8/mlsdb.data
%{_datadir}/geoclue-provider-mlsdb/au/9/mlsdb.data
