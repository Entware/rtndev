#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mqtt-exec
PKG_VERSION:=0.5
PKG_REV:=da665e304315bc0f60069bf5bf7d610b7eaebb02
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/ncopa/mqtt-exec.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=050239802792e8781b880745877f2b7e0ea4a9bf222bb5c41f51b4fe8351dfa0

include $(INCLUDE_DIR)/package.mk

define Package/mqtt-exec
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libmosquitto-ssl
	TITLE:=mqtt subscriber that executes a command
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mqtt-exec/description
 A simple mqtt subscriber that executes a command on mqtt messages
endef

define Package/mqtt-exec/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mqtt-exec $(1)/opt/bin
endef

$(eval $(call BuildPackage,mqtt-exec))
