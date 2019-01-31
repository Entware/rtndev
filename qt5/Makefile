#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# ported to Entware from
# https://github.com/KryptonLee/qBittorrent-openwrt-package and
# https://github.com/pawelkn/qt5-openwrt-package

include $(TOPDIR)/rules.mk

PKG_NAME:=qt5
PKG_VERSION:=5.12.0
PKG_RELEASE:=2

PKG_SOURCE:=qt-everywhere-src-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://download.qt-project.org/archive/qt/5.12/$(PKG_VERSION)/single
PKG_HASH:=356f42d9087718f22f03d13d0c2cdfb308f91dc3cf0c6318bed33f2094cd9d6c

PKG_BUILD_PARALLEL:=1
PKG_USE_MIPS16:=0

PKG_BUILD_DIR=$(BUILD_DIR)/qt-everywhere-src-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

ifndef CONFIG_USE_GLIBC
# not using sstrip here as this fucks up the .so's somehow
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
	TITLE:=qt5
	URL:=http://qt-project.org
	DEPENDS:=+librt +libstdcpp +libpthread @!LINUX_2_6_36
endef

define Package/qt5-core
	$(call Package/qt5/Default)
	TITLE+=core
	DEPENDS+=+libatomic
endef

define Package/qt5-network
	$(call Package/qt5/Default)
	TITLE+=network
	DEPENDS+=+qt5-core
endef

define Package/qt5-xml
	$(call Package/qt5/Default)
	TITLE+=xml
	DEPENDS+=+qt5-core
endef

define Build/Configure
	$(SED) 's@$$$$(TARGET_CROSS)@$(TARGET_CROSS)@g' $(PKG_BUILD_DIR)/qtbase/mkspecs/linux-openwrt-g++/qmake.conf
	$(SED) 's@$$$$(TARGET_CFLAGS)@$(TARGET_CFLAGS)@g' $(PKG_BUILD_DIR)/qtbase/mkspecs/linux-openwrt-g++/qmake.conf
	( cd $(PKG_BUILD_DIR) ; \
		./configure \
			-prefix /opt \
			-extprefix $(TOOLCHAIN_DIR) \
			-sysroot $(TOOLCHAIN_DIR) \
			-plugindir /opt/lib/Qt/plugins \
			-xplatform linux-openwrt-g++ \
			-opensource \
			-confirm-license \
			-R /opt/lib \
			-qt-freetype \
			-qt-zlib \
			-no-cups \
			-no-dbus \
			-no-directfb \
			-no-eglfs \
			-no-feature-getentropy \
			-no-iconv \
			-no-kms \
			-no-opengl \
			-no-pch \
			-no-sql-psql \
			-no-strip \
			-no-xcb \
			-no-gui \
			-no-widgets \
			-make libs \
			-nomake examples \
			-nomake tests \
			-nomake tools \
			-skip 3d \
			-skip activeqt \
			-skip charts \
			-skip connectivity \
			-skip datavis3d \
			-skip declarative \
			-skip doc \
			-skip gamepad \
			-skip imageformats \
			-skip location \
			-skip networkauth \
			-skip multimedia \
			-skip purchasing \
			-skip remoteobjects \
			-skip script \
			-skip sensors \
			-skip serialbus \
			-skip serialport \
			-skip speech \
			-skip svg \
			-skip wayland \
			-skip webengine \
			-skip websockets \
			-skip webchannel \
			-skip xmlpatterns \
			-v \
	)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)
endef

define Build/InstallDev
	$(MAKE) -C $(PKG_BUILD_DIR) install
	$(CP) $(PKG_BUILD_DIR)/qtbase/bin/qt.conf $(TOOLCHAIN_DIR)/bin
	$(RM) $(TOOLCHAIN_DIR)/bin/qt{diag,paths,plugininfo}
endef

define Package/qt5-core/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/qtbase/lib/libQt5Core.so* $(1)/opt/lib
endef

define Package/qt5-network/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/qtbase/lib/libQt5Network.so* $(1)/opt/lib
endef

define Package/qt5-xml/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/qtbase/lib/libQt5Xml.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,qt5-core))
$(eval $(call BuildPackage,qt5-network))
$(eval $(call BuildPackage,qt5-xml))
