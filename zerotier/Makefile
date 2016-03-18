#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=zerotier
PKG_VERSION:=1.1.4
PKG_REV:=9cc2733ed877faed30154035f0efe95633e88ac2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/zerotier/ZeroTierOne
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/zerotier
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=VPN
	DEPENDS:=+libstdcpp +libpthread +libsqlite3
	TITLE:=Ethernet virtualization engine
	URL:=https://www.zerotier.com/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/zerotier/description
 Create flat virtual Ethernet networks of almost unlimited size.
endef

MAKE_VARS += ZT_ENABLE_NETWORK_CONTROLLER=1

define Package/zerotier/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/zerotier-one $(1)/opt/bin
	$(LN) zerotier-one $(1)/opt/bin/zerotier-cli
	$(LN) zerotier-one $(1)/opt/bin/zerotier-idtool
	$(INSTALL_DIR) $(1)/opt/var/lib/zerotier-one
endef

$(eval $(call BuildPackage,zerotier))
