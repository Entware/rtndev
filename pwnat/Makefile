#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pwnat
PKG_VERSION:=0.3-20171222
PKG_REV:=5de412c8cf90a8745f2fa8eacad498cf8649b589
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/samyk/pwnat.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/pwnat
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Firewall
#	DEPENDS:=+libmbedtls
	TITLE:=NAT traversal tool
	URL:=https://samy.pl/pwnat/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pwnat/description
 The only tool to punch holes through firewalls/NATs where both
 clients and server can be behind separate NATs without any 3rd party
 involvement.
endef

define Package/pwnat/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pwnat $(1)/opt/sbin
endef

$(eval $(call BuildPackage,pwnat))
