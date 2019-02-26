#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=multitail
PKG_VERSION:=6.4.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=https://www.vanheusden.com/multitail
PKG_HASH:=af1d5458a78ad3b747c5eeb135b19bdca281ce414cefdc6ea0cff6d913caa1fd

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

define Package/multitail/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/multitail $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/multitail.conf $(1)/opt/etc
endef

$(eval $(call BuildPackage,multitail))
