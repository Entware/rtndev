#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=phodav
PKG_VERSION:=2.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=@GNOME/$(PKG_NAME)/$(PKG_VERSION)
PKG_HASH:=71f0a9cd70afd4dd1412a0298331dbb8ac71c0377f52117afc15eb88dc6fb910

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(TOPDIR)/feeds/packages/devel/meson/meson.mk

define Package/phodav
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	DEPENDS:=+libsoup
	TITLE:=WebDAV implementation
	URL:=https://wiki.gnome.org/phodav
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/phodav/description
 Phodav was initially developed as a filesharing mechanism for Spice,
 but it is generic enough to be reused in other projects, in particular
 in the GNOME desktop.
endef

define Package/phodav/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/chezdav $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libphodav-2.0.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,phodav))
