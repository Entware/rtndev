# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=phodav
PKG_VERSION:=3.0
# libxml2
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=@GNOME/$(PKG_NAME)/$(PKG_VERSION)
PKG_HASH:=392ec2d06d50300dcff1ef269a2a985304e29bce3520002fca29f2edc1d138d1

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=LGPL-2.1-or-later
PKG_LICENSE_FILES:=COPYING

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/meson.mk

define Package/phodav
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web Servers/Proxies
  TITLE:=WebDAV implementation
  URL:=https://wiki.gnome.org/phodav
  DEPENDS:=+glib2 +libsoup3 +libxml2 $(INTL_DEPENDS)
endef

define Package/phodav/description
 Phodav was initially developed as a filesharing mechanism for Spice,
 but it is generic enough to be reused in other projects, in particular
 in the GNOME desktop.
endef

MESON_ARGS += \
	-Dgtk_doc=disabled \
	-Davahi=disabled

define Package/phodav/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/chezdav $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libphodav-3.0.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,phodav))
