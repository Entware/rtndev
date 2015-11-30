#
# Copyright (C) 2011-2015 Entware, Zyxmon.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=balance
PKG_VERSION:=3.57
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.inlab.de
PKG_MD5SUM:=12ab710435bc4119293837375c6e1f97

include $(INCLUDE_DIR)/package.mk

define Package/balance
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	TITLE:=load balancing proxy
	URL:=http://www.inlab.de/balance.html
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/balance/description
 Balance is successful load balancing solution being a simple but powerful
 generic tcp proxy with round robin load balancing and failover mechanisms.
endef

define Package/balance/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/balance $(1)/opt/bin
endef

$(eval $(call BuildPackage,balance))
