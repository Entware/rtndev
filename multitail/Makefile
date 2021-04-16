#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Project archieved

include $(TOPDIR)/rules.mk

PKG_NAME:=multitail
PKG_VERSION:=6.5.0
PKG_REV:=2c8f90cd253b270afa88c9845c8a927bb4fbb4e5
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/flok99/multitail.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=4dac4f9052f6b300c71f7be21fa06c6c7d83b5dc909c3434c7ae71d1c060674b

include $(INCLUDE_DIR)/package.mk

define Package/multitail
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libncursesw
	TITLE:=log file monitor
	URL:=https://www.vanheusden.com/multitail
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/multitail/description
 MultiTail allows you to monitor logfiles and command output in multiple
 windows in a terminal, colorize, filter and merge.
endef

define Package/multitail/conffiles
/opt/etc/multitail.conf
endef

define Build/Configure
	$(RM) $(PKG_BUILD_DIR)/GNUmakefile
	$(call Build/Configure/Default)
endef

define Package/multitail/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/multitail $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/multitail.conf $(1)/opt/etc
endef

$(eval $(call BuildPackage,multitail))
