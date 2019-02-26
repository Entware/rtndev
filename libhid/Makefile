#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by wmr-oregon only. No need to be updated.

include $(TOPDIR)/rules.mk

PKG_NAME:=libhid
PKG_VERSION:=0.2.16
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://sources.openelec.tv/mirror/libhid
PKG_HASH:=f6809ab3b9c907cbb05ceba9ee6ca23a705f85fd71588518e14b3a7d9f2550e5

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libhid
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libusb-compat
	TITLE:=a user-space USB HID access library
	URL:=http://libhid.alioth.debian.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libhid/description
 libhid provides a generic and flexible way to access and interact with USB HID
 devices, much like libusb does for plain USB devices. It is based on libusb
 0.1, thus it requires no special HID support in the kernel. Furthermore, it
 aims to support all operating system supported by libusb.
endef

CONFIGURE_ARGS += \
	--disable-swig \
	--disable-werror \
	--without-doxygen \

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/*.h $(1)/opt/include/
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libhid.{a,la,so*} $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libhid.pc $(1)/opt/lib/pkgconfig/
endef

define Package/libhid/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libhid.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/libhid-detach-device $(1)/opt/bin
endef

$(eval $(call BuildPackage,libhid))
