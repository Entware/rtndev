#
# Copyright (C) 2007 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Deluge gliches with newer version

include $(TOPDIR)/rules.mk

PKG_NAME:=rblibtorrent
PKG_VERSION:=1.1.6
PKG_RELEASE:=1

PKG_SOURCE:=libtorrent-rasterbar-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/arvidn/libtorrent/releases/download/libtorrent-1_1_6
PKG_HASH:=b7c74d004bd121bd6e9f8975ee1fec3c95c74044c6a6250f6b07f259f55121ef
PKG_BUILD_DIR:=$(BUILD_DIR)/libtorrent-rasterbar-$(PKG_VERSION)
PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/rblibtorrent
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Rasterbar BitTorrent library
  URL:=http://www.rasterbar.com/products/libtorrent/
  DEPENDS:=+boost-python +boost-filesystem +boost-regex +boost-thread +boost-program_options +boost-system +libopenssl \
	+boost-random
endef

define Package/rblibtorrent/description
Rasterbar libtorrent is a C++ library that aims to be a good alternative to
all the other bittorrent implementations around. It is a library and not a
full featured client, although it comes with a working example client.
endef

CONFIGURE_ARGS+= \
	--disable-debug \
	--enable-python-binding \
	--with-openssl=$(STAGING_DIR)/opt \
	--with-boost=$(STAGING_DIR)/opt/include \
	--with-boost-libdir=$(STAGING_DIR)/opt/lib \
	--with-boost-python=yes

CONFIGURE_VARS+= CC=$(TARGET_CXX)

# Ensure target python headers come bore host headers!!!
TARGET_CFLAGS+="-I$(STAGING_DIR)/opt/include/python2.7/"

define Build/InstallDev
	mkdir -p $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/libtorrent $(1)/opt/include/
	mkdir -p $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib/
	mkdir -p $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libtorrent-rasterbar.pc $(1)/opt/lib/pkgconfig/
endef

define Package/rblibtorrent/install
	$(INSTALL_DIR) $(1)/opt/lib $(1)/opt/lib/python2.7/site-packages/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/python2.7/site-packages/*.so* $(1)/opt/lib/python2.7/site-packages/
endef

$(eval $(call BuildPackage,rblibtorrent))
