# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/956

include $(TOPDIR)/rules.mk

PKG_NAME:=vifm
PKG_VERSION:=0.14.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/vifm/vifm/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=9e21e69f0bfa00a470c01f4b83e011af6a4e69626237a8d12afc0d79a7819be8

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=COPYING COPYING.3party

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/vifm
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Vim-like file manager
  URL:=https://vifm.info/
  DEPENDS:=+file +glib2 +libncursesw $(INTL_DEPENDS)
endef

define Package/vifm/description
  Vifm is a file manager with curses interface, which provides
 Vim-like environment for managing objects within file systems, extended with
 some useful ideas from mutt. If you use vi, Vifm gives you complete keyboard
 control over your files without having to learn a new set of commands.
endef

CONFIGURE_ARGS += \
	--disable-desktop-files \
	--without-dyn-X11 \
	--without-X11

define Package/vifm/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/vifm $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/vifm $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/vifm $(1)/opt/share
endef

$(eval $(call BuildPackage,vifm))
