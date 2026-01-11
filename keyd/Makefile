# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025-2026 Entware

# https://github.com/Entware/Entware/issues/987

include $(TOPDIR)/rules.mk

PKG_NAME:=keyd
PKG_VERSION:=2.6.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/rvaiya/keyd/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=697089681915b89d9e98caf93d870dbd4abce768af8a647d54650a6a90744e26

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/keyd
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=key remapping daemon
  URL:=https://github.com/rvaiya/keyd
endef

define Package/keyd/description
  A key remapping daemon for linux.
endef

define Package/keyd/conffiles
/opt/etc/keyd/default.conf
endef

define Package/keyd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/keyd $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/keyd
	$(CP) ./files/default.conf $(1)/opt/etc/keyd
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/{doc,keyd} $(1)/opt/share
endef

$(eval $(call BuildPackage,keyd))
