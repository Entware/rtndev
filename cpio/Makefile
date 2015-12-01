#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cpio
PKG_VERSION:=2.12
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@GNU/$(PKG_NAME)
PKG_MD5SUM:=fc207561a86b63862eea4b8300313e86

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/cpio
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=manage archives of files
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/cpio/description
 GNU cpio does a superior job of suggesting possible replacements for
 a misspelled word than just about any other spell checker out there for
 the English (and some other) language.
endef

define Package/cpio/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cpio $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/rmt $(1)/opt/lib
endef

$(eval $(call BuildPackage,cpio))
