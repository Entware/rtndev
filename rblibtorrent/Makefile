#
# Copyright (C) 2007 OpenWrt
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rblibtorrent
PKG_VERSION:=1.1.14
PKG_RELEASE:=1

PKG_SOURCE:=libtorrent-rasterbar-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/arvidn/libtorrent/releases/download/libtorrent-$(subst .,_,$(PKG_VERSION))
PKG_HASH:=244f0f189ba8ab9801e7fcf553beebfb83d7c86b

PKG_BUILD_DIR:=$(BUILD_DIR)/libtorrent-rasterbar-$(PKG_VERSION)

PKG_FIXUP:=autoreconf libtool
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/rblibtorrent
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Rasterbar BitTorrent library
  URL:=http://www.rasterbar.com/products/libtorrent/
  DEPENDS:=+boost-chrono +boost-python3 +boost-random +boost-system +libopenssl
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
	CPPFLAGS="$(TARGET_CPPFLAGS) $(shell $(STAGING_DIR)/host/bin/python$(PYTHON3_VERSION)-config --includes)" \
	LDFLAGS="$(TARGET_LDFLAGS)" \
	PYTHON=$(STAGING_DIR_HOSTPKG)/bin/python$(PYTHON3_VERSION) \
	PYTHON_CPPFLAGS="-I$(STAGING_DIR)/opt/include/python$(PYTHON3_VERSION)" \
	PYTHON_LDFLAGS="$(shell $(STAGING_DIR)/host/bin/python$(PYTHON3_VERSION)-config --libs)" \
	PYTHON_LIBS="-L$(STAGING_DIR)/opt/lib -lpython$(PYTHON3_VERSION)" \
	PYTHON_SITE_PKG="$(STAGING_DIR)/opt/lib/python$(PYTHON3_VERSION)/site-packages"

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/libtorrent $(1)/opt/include/
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libtorrent-rasterbar.pc $(1)/opt/lib/pkgconfig/
endef

define Package/rblibtorrent/install
	$(INSTALL_DIR) $(1)/opt/lib/python$(PYTHON3_VERSION)/site-packages
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/python$(PYTHON3_VERSION)/site-packages/*.so* $(1)/opt/lib/python$(PYTHON3_VERSION)/site-packages/
endef

$(eval $(call BuildPackage,rblibtorrent))
