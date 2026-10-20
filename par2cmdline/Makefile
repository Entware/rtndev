# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=par2cmdline
PKG_VERSION:=1.4.0
PKG_REV:=3a27718ac77e638bd4ad5c2f14a2349759fcec15
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/Parchive/par2cmdline.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=2e4da8f96c8f243a454554d8e7c17e3fa8ca3b18c44ca76af27bcce81b45ddb5

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/par2cmdline
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libstdcpp
	TITLE:=file verification and repair tool
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/par2cmdline/description
 par2cmdline is a PAR 2.0 compatible file verification and repair tool.
endef

define Package/par2cmdline/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/par2 $(1)/opt/bin
	$(FIND) $(PKG_INSTALL_DIR)/opt/bin -type l -exec $(CP) -a {} $(1)/opt/bin \;
endef

$(eval $(call BuildPackage,par2cmdline))
