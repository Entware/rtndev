#
# Copyright (C) 2017-2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# ported to Entware from
# https://github.com/KryptonLee/qBittorrent-openwrt-package and
# https://github.com/pawelkn/qt5-openwrt-package

include $(TOPDIR)/rules.mk

PKG_NAME:=qt5
PKG_VERSION:=5.15.9
PKG_RELEASE:=1

PKG_SOURCE:=qt-everywhere-opensource-src-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://download.qt-project.org/archive/qt/5.15/$(PKG_VERSION)/single \
		https://ftp.fau.de/qtproject/archive/qt/5.15/$(PKG_VERSION)/single
PKG_HASH:=26d5f36134db03abe4a6db794c7570d729c92a3fc1b0bf9b1c8f86d0573cd02f

PKG_BUILD_DIR:=$(BUILD_DIR)/qt-everywhere-src-$(PKG_VERSION)

PKG_BUILD_PARALLEL:=1
PKG_BUILD_FLAGS:=no-mips16

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

ifndef CONFIG_USE_GLIBC
# not using sstrip here as this screw up the .so's somehow
STRIP:=/bin/true
RSTRIP:= \
	NM="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)nm" \
	STRIP="$(STRIP)" \
	STRIP_KMOD="$(STRIP)" \
	$(SCRIPT_DIR)/rstrip.sh
endif

define Package/qt5/Default
	SECTION:=libs
	CATEGORY:=Libraries
	SUBMENU:=Qt5
	TITLE:=Qt5
	URL:=http://qt-project.org
	DEPENDS:=+libstdcpp
endef

define Package/qt5-core
	$(call Package/qt5/Default)
	TITLE+=Core module
	DEPENDS+=+libatomic $(INTL_DEPENDS)
endef

define Package/qt5-network
	$(call Package/qt5/Default)
	TITLE+=Network module
	DEPENDS+=+libopenssl +qt5-core
endef

define Package/qt5-sql
	$(call Package/qt5/Default)
	TITLE+=Sql module
	DEPENDS+=+qt5-core
endef

define Package/qt5-xml
	$(call Package/qt5/Default)
	TITLE+=Xml module
	DEPENDS+=+qt5-core
endef

# getrandom since Linux 3.17 & getentropy glibc 2.25
# renameat2/statx since Linux 3.15/4.11 & glibc 2.28
QT_CONFIGURE_OPTS:= \
	-no-feature-getentropy \
	-no-feature-renameat2 \
	-no-feature-statx

# Qt modules and options:
QT_CONFIGURE_OPTS += \
	-no-dbus \
	-no-gui \
	-no-feature-concurrent \
	-no-feature-testlib \
	-no-widgets

# Support enabled for:
QT_CONFIGURE_OPTS += \
	-no-libudev \
	-no-zstd \
	-qt-zlib

# Qt Core:
QT_CONFIGURE_OPTS += \
	-no-glib \
	-no-iconv \
	-no-icu \
	-no-journald \
	-no-slog2 \
	-no-syslog \
	-qt-doubleconversion \
	-qt-pcre

# Qt Network:
QT_CONFIGURE_OPTS += \
	-no-feature-gssapi

# Qt Gui:
QT_CONFIGURE_OPTS += \
	-no-accessibility \
	-no-fontconfig \
	-no-freetype \
	-no-harfbuzz \
	-no-gif \
	-no-ico \
	-no-libjpeg \
	-no-libpng \
	-no-eglfs \
	-no-opengl \
	-no-openvg \
	-no-sm \
	-no-vulkan \
	-no-feature-vkgen \
	-no-libmd4c

# Features used by QPA backends:
QT_CONFIGURE_OPTS += \
	-no-evdev \
	-no-libinput \
	-no-mtdev \
	-no-tslib \
	-no-feature-xlib\
	-no-xkbcommon

# QPA backends:
QT_CONFIGURE_OPTS += \
	-no-directfb \
	-no-linuxfb \
	-no-feature-vnc \
	-no-gbm \
	-no-kms \
	-no-xcb

# Qt Widgets:
QT_CONFIGURE_OPTS += \
	-no-gtk

# Qt PrintSupport:
QT_CONFIGURE_OPTS += \
	-no-cups

# Qt Sql Drivers:
QT_CONFIGURE_OPTS += \
	-no-sql-db2 \
	-no-sql-ibase \
	-no-sql-mysql \
	-no-sql-oci \
	-no-sql-odbc \
	-no-sql-psql \
	-no-sql-sqlite \
	-no-sql-sqlite2 \
	-no-sql-tds

# Qt Testlib:
QT_CONFIGURE_OPTS += \
	-no-feature-itemmodeltester

# Qt Tools:
QT_CONFIGURE_OPTS += \
	-no-feature-assistant \
	-no-feature-designer \
	-no-feature-distancefieldgenerator \
	-no-feature-kmap2qmap \
	-no-feature-makeqpf \
	-no-feature-pdf \
	-no-feature-pixeltool\
	-no-feature-qdbus\
	-no-feature-qev \
	-no-feature-qtattributionsscanner \
	-no-feature-qtdiag \
	-no-feature-qtpaths \
	-no-feature-qtplugininfo

# no skip: tools (linguist)
QT_CONFIGURE_OPTS += \
	-skip 3d \
	-skip activeqt \
	-skip androidextras \
	-skip charts \
	-skip connectivity \
	-skip datavis3d \
	-skip declarative \
	-skip doc \
	-skip gamepad \
	-skip graphicaleffects \
	-skip imageformats \
	-skip location \
	-skip lottie \
	-skip macextras \
	-skip multimedia \
	-skip networkauth \
	-skip purchasing \
	-skip quick3d \
	-skip quickcontrols \
	-skip quickcontrols2 \
	-skip quicktimeline \
	-skip remoteobjects \
	-skip script \
	-skip scxml \
	-skip sensors \
	-skip serialbus \
	-skip serialport \
	-skip speech \
	-skip svg \
	-skip translations \
	-skip virtualkeyboard \
	-skip wayland \
	-skip webchannel \
	-skip webengine \
	-skip webglplugin \
	-skip websockets \
	-skip webview \
	-skip winextras \
	-skip x11extras \
	-skip xmlpatterns

# x86 options
ifneq ($(or $(CONFIG_i386),$(CONFIG_x86_64)),y)
QT_CONFIGURE_OPTS += \
	-no-avx \
	-no-avx2 \
	-no-feature-intelcet \
	-no-feature-rdrnd \
	-no-feature-rdseed \
	-no-sse2 \
	-no-sse3 \
	-no-ssse3 \
	-no-sse4.1 \
	-no-sse4.2
else
QT_CONFIGURE_OPTS += \
	-no-feature-intelcet \
	-no-feature-rdseed
endif

PKG_JOBS:=-j$(shell nproc)

define Build/Configure
	$(SED) 's,^QMAKE_CC\s*=.*,QMAKE_CC = $(HOSTCC_NOCACHE),; \
		s,^QMAKE_CXX\s*=.*,QMAKE_CXX = $(HOSTCXX_NOCACHE),' \
			$(PKG_BUILD_DIR)/qtbase/mkspecs/common/g++-base.conf
	$(SED) 's,@TARGET_CFLAGS@,$(TARGET_CFLAGS),g; \
		s,@TARGET_CXXFLAGS@,$(TARGET_CXXFLAGS),g' \
			$(PKG_BUILD_DIR)/qtbase/mkspecs/devices/linux-entware-g++/qmake.conf
	$(SED) 's,@ICONV_PREFIX@,$(ICONV_PREFIX),g; \
		s,@INTL_PREFIX@,$(INTL_PREFIX),' \
		$(PKG_BUILD_DIR)/qtbase/src/corelib/configure.json
	( cd $(PKG_BUILD_DIR); \
		MAKEFLAGS="$(PKG_JOBS) $(MAKEFLAGS)" \
		OPENSSL_LIBS="-L$(STAGING_DIR)/opt/lib -lssl -lcrypto" \
		./configure -v \
			-prefix /opt \
			-docdir /opt/share/doc/Qt5 \
			-headerdir /opt/include/Qt5 \
			-plugindir /opt/lib/Qt5/plugins \
			-qmldir /opt/lib/Qt5/qml \
			-translationdir /opt/share/Qt5/translations \
			-extprefix $(STAGING_DIR)/opt \
			-hostprefix $(TOOLCHAIN_DIR) \
			-sysroot $(STAGING_DIR) \
			-I $(STAGING_DIR)/opt/include \
			-L $(STAGING_DIR)/opt/lib \
			-L $(ICONV_PREFIX)/lib \
			-L $(INTL_PREFIX)/lib \
			-R /opt/lib \
			-device entware \
			-device-option CROSS_COMPILE="$(TARGET_CROSS)" \
			-opensource \
			-confirm-license \
			-platform linux-g++ \
			-release \
			-shared \
			-no-optimize-debug \
			-no-pch \
			-no-reduce-relocations \
			-no-feature-relocatable \
			-no-compile-examples \
			-nomake examples \
			-nomake tests \
			-nomake tools \
			-openssl-linked \
			$(QT_CONFIGURE_OPTS) \
	)
endef

define Build/Compile
	$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR)
endef

define Build/Clean
	# host
	rm -f $(TOOLCHAIN_DIR)/bin/fixqt4headers.pl
	rm -f $(TOOLCHAIN_DIR)/bin/lconvert
	rm -f $(TOOLCHAIN_DIR)/bin/lprodump
	rm -f $(TOOLCHAIN_DIR)/bin/lrelease*
	rm -f $(TOOLCHAIN_DIR)/bin/lupdate*
	rm -f $(TOOLCHAIN_DIR)/bin/moc
	rm -f $(TOOLCHAIN_DIR)/bin/qlalr
	rm -f $(TOOLCHAIN_DIR)/bin/qmake
	rm -f $(TOOLCHAIN_DIR)/bin/qt.conf
	rm -f $(TOOLCHAIN_DIR)/bin/rcc
	rm -f $(TOOLCHAIN_DIR)/bin/syncqt.pl
	rm -f $(TOOLCHAIN_DIR)/bin/tracegen
	rm -f $(TOOLCHAIN_DIR)/lib/libQt5Bootstrap.*
	rm -f -r $(TOOLCHAIN_DIR)/mkspecs
	# target
	rm -f -r $(STAGING_DIR)/opt/include/Qt5
	rm -f -r $(STAGING_DIR)/opt/lib/cmake/Qt5*
	rm -f -r $(STAGING_DIR)/opt/lib/metatypes
	rm -f $(STAGING_DIR)/opt/lib/pkgconfig/Qt5*.pc
	rm -f -r $(STAGING_DIR)/opt/lib/Qt5
	rm -f $(STAGING_DIR)/opt/lib/*Qt5*.{la,prl,so*}
	rm -f -r $(STAGING_DIR)/opt/share/doc/Qt5
endef

define Build/InstallDev
	$(CP) $(PKG_BUILD_DIR)/qtbase/bin/qt.conf $(TOOLCHAIN_DIR)/bin
	$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR)/qtbase install
	# bins - lconvert  lprodump  lrelease  lrelease-pro  lupdate  lupdate-pro
	$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR)/qttools install
endef

define Package/qt5-core/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/qtbase/lib/libQt5Core.so* $(1)/opt/lib
endef

define Package/qt5-network/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/qtbase/lib/libQt5Network.so* $(1)/opt/lib
endef

define Package/qt5-sql/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/qtbase/lib/libQt5Sql.so* $(1)/opt/lib
endef

define Package/qt5-xml/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/qtbase/lib/libQt5Xml.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,qt5-core))
$(eval $(call BuildPackage,qt5-network))
$(eval $(call BuildPackage,qt5-sql))
$(eval $(call BuildPackage,qt5-xml))
