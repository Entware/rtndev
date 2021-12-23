#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ioping
PKG_VERSION:=1.2
PKG_REV:=655af3df22b13b849608f728c1357cc53dc525a7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/koct9i/ioping.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=4548f3bf184ba0f048608b5ea32a219144282c421a2022e0972667a0a1eb5e01

include $(INCLUDE_DIR)/package.mk

define Package/ioping
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=simple disk I/0 latency measuring tool
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ioping/description
 A tool to monitor I/O latency in real time. It shows disk latency in the same
 way as ping shows network latency.
endef

define Package/ioping/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ioping $(1)/opt/bin
endef

$(eval $(call BuildPackage,ioping))
