#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=multitail
PKG_VERSION:=6.5.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=https://www.vanheusden.com/multitail
PKG_HASH:=b29d5e77dfc663c7500f78da67de5d82d35d9417a4741a89a18ce9ee7bdba9ed

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
