#
# Copyright (C) 2007 OpenWrt
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rblibtorrent
PKG_VERSION:=1.1.13
PKG_RELEASE:=1

PKG_SOURCE:=libtorrent-rasterbar-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/arvidn/libtorrent/releases/download/libtorrent-1_1_13
#PKG_HASH:=

PKG_BUILD_DIR:=$(BUILD_DIR)/libtorrent-rasterbar-$(PKG_VERSION)

PKG_FIXUP:=autoreconf libtool
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/rblibtorrent
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Rasterbar BitTorrent library
  URL:=http://www.rasterbar.com/products/libtorrent/
  DEPENDS:=+boost-chrono +boost-python +boost-random +boost-system +libopenssl
endef

define Package/rblibtorrent/description
Rasterbar libtorrent is a C++ library that aims to be a good alternative to
all the other bittorrent implementations around. It is a library and not a
full featured client, although it comes with a working example client.
endef

CONFIGURE_ARGS += \
	--disable-debug \
	--enable-python-binding \
	--with-openssl=$(STAGING_DIR)/opt \
	--with-boost=$(STAGING_DIR)/opt \
	--with-boost-libdir=$(STAGING_DIR)/opt/lib \
	CC=$(TARGET_CXX) \
	CPPFLAGS="$(TARGET_CPPFLAGS) $(shell $(STAGING_DIR)/host/bin/python2.7-config --includes)" \
	LDFLAGS="$(TARGET_LDFLAGS)" \
	PYTHON=$(STAGING_DIR_HOSTPKG)/bin/python \
	PYTHON_CPPFLAGS="-I$(STAGING_DIR)/opt/include/python2.7" \
	PYTHON_LDFLAGS="$(shell $(STAGING_DIR)/host/bin/python2.7-config --libs)" \
	PYTHON_LIBS="-L$(STAGING_DIR)/opt/lib -lpython2.7" \
	PYTHON_SITE_PKG="$(STAGING_DIR)/opt/lib/python2.7/site-packages"

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/libtorrent $(1)/opt/include/
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libtorrent-rasterbar.pc $(1)/opt/lib/pkgconfig/
endef

define Package/rblibtorrent/install
	$(INSTALL_DIR) $(1)/opt/lib $(1)/opt/lib/python2.7/site-packages/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/python2.7/site-packages/*.so* $(1)/opt/lib/python2.7/site-packages/
endef

$(eval $(call BuildPackage,rblibtorrent))
