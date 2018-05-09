#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libebml
PKG_VERSION:=1.3.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://dl.matroska.org/downloads/libebml
PKG_HASH:=d818413f60742c2f036ba6f582c5e0320d12bffec1b0fc0fc17a398b6f04aa00

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libebml
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=Extensible Binary Meta Language access library
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libebml/description
 libEBML - Extensible Binary Meta Language access library
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ebml $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libebml.{a,la,so*} $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libebml.pc $(1)/opt/lib/pkgconfig/
endef

define Package/libebml/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libebml.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libebml))
