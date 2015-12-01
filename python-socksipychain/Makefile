#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#


include $(TOPDIR)/rules.mk

PKG_NAME:=python-socksipychain
PKG_VERSION:=2.0.15
PKG_RELEASE:=1

PKG_SOURCE:=SocksipyChain-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://pagekite.net/pk/src/$(PKG_SOURCE)
PKG_MD5SUM:=6b0a0bf44ef6a6300e13216a2998f8ba

PKG_BUILD_DIR:=$(BUILD_DIR)/SocksipyChain-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/$(PKG_NAME)
	SUBMENU:=Python
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=Chaining support for socksipy
	URL:=https://pagekite.net/wiki/Floss/PySocksipyChain/
	DEPENDS:=+python-setuptools
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/$(PKG_NAME)/description
 Chaining support for socksipy - a Python SOCKS client module. It provides
 a socket-like interface that supports connections to any TCP service through
 the use of a SOCKS4, SOCKS5 or HTTP proxy.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install \
	    --prefix=/opt \
	    --root=$(PKG_INSTALL_DIR) \
	)
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)/
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin/
	$(SED) 's,/opt/bin/python2.7,/opt/bin/python,g' $(1)/opt/bin/sockschain
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
