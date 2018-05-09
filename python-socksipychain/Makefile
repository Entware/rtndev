#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by pagekite only

include $(TOPDIR)/rules.mk

PKG_NAME:=python-socksipychain
PKG_VERSION:=2.0.15b
PKG_RELEASE:=1

PKG_SOURCE:=SocksipyChain-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://pagekite.net/pk/src/$(PKG_SOURCE)
PKG_HASH:=a2ec72a1fbb22e1e59b74c0f3e1d436602e7ccb6553c52bb49bbc5850a4cc089

PKG_BUILD_DIR:=$(BUILD_DIR)/SocksipyChain-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/$(PKG_NAME)
	SUBMENU:=Python
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=Chaining support for socksipy
	URL:=https://pagekite.net/wiki/Floss/PySocksipyChain/
	DEPENDS:=+python-setuptools
	MAINTAINER:=Entware team, https://entware.net
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
