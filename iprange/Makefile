# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=iprange
PKG_VERSION:=2.1.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/firehol/iprange/releases/download/v$(PKG_VERSION)
PKG_HASH:=34237002ffc47f2d20f18db0117a60663d099419132ad2cf307336479b3d7db5

include $(INCLUDE_DIR)/package.mk

define Package/iprange
	SECTION:=net
	CATEGORY:=Network
	TITLE:=manage IP ranges
	URL:=https://github.com/firehol/iprange
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/iprange/description
 Manage IP ranges.
endef

define Package/iprange/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/iprange $(1)/opt/bin
endef

$(eval $(call BuildPackage,iprange))
