#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Based on Karl Palsson's makefile
# https://github.com/remakeelectric/owrt_pub_feeds/tree/master/pagekitepy

include $(TOPDIR)/rules.mk

PKG_NAME:=pagekite
PKG_VERSION:=0.5.9.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://pagekite.net/pk/src/$(PKG_SOURCE)
PKG_HASH:=10fa1464029cdf2430ee01f833d466f63163bd5065995da395a3edb929137695

PKG_BUILD_DEPENDS:=python

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/$(PKG_NAME)
	SECTION:=net
	CATEGORY:=Network
	TITLE:=Make localhost servers publicly visible.
	URL:=http://pagekite.net
	DEPENDS+=+python +python-openssl +openssl-util +python-socksipychain +net-tools-arp
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/$(PKG_NAME)/description
 PageKite is a system for running publicly visible servers (generally
 web servers) on machines without a direct connection to the Internet,
 such as mobile devices or computers behind restrictive firewalls.
 PageKite works around NAT, firewalls and IP-address limitations by
 using a combination of  tunnels and reverse proxies.
endef

define Package/$(PKG_NAME)/conffiles
/opt/etc/pagekite.d/pagekite.rc
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)/

	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/etc/pagekite.d $(1)/opt/etc
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/bin/* \
	    $(1)/opt/bin/
	$(INSTALL_CONF) ./files/pagekite.rc $(1)/opt/etc/pagekite.d
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
