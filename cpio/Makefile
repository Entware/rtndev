#
# Copyright (C) 2011-2024 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cpio
PKG_VERSION:=2.15
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@GNU/$(PKG_NAME)
PKG_HASH:=efa50ef983137eefc0a02fdb51509d624b5e3295c980aa127ceee4183455499e

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/cpio
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=manage archives of files
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cpio/description
 GNU cpio copies files between archives and directories.  It supports
 the following archive formats: old binary cpio, old portable cpio, SVR4
 cpio with and without checksum, HP cpio, and various tar formats.
endef

define Package/cpio/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cpio $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/rmt $(1)/opt/lib
endef

$(eval $(call BuildPackage,cpio))
