#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2014

include $(TOPDIR)/rules.mk

PKG_NAME:=weave-minimal
PKG_VERSION:=1.5.1
PKG_RELEASE:=4

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/9d/1f/d9d4ebcf0c376e61b2fb3ea597259c0329c0c268294fae871fa6b7f5db04
PKG_HASH:=6799fe276ed8e2abdd7ea5eade9a72b13fd5e2cabe818ad530fc115852f78d22

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/weave-minimal
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+python-sqlite3 +python-werkzeug +dtach +python-gevent +python-openssl +python-setuptools
	TITLE:=a Firefox Sync Server
	URL:=https://github.com/posativ/weave-minimal
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/weave-minimal/description
 This is a lightweight implementation of Mozilla User API v1.0 and Storage
 API v1.1 without LDAP, MySQL, Redis etc. overhead.
 DOES NOT WORK WITH FIREFOX 29 OR LATER.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install \
	    --prefix=/opt \
	    --root="$(PKG_INSTALL_DIR)" \
	)
endef

define Package/weave-minimal/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
	$(SED) 's,$(HOST_PYTHON_BIN),/opt/bin/python,g' \
	    $(PKG_INSTALL_DIR)/opt/bin/weave-minimal
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/weave-minimal $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S92weave-minimal $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/var/weave
endef

define Package/weave-minimal/postinst
#!/bin/sh

echo Don\'t forget to add new user by
echo \'weave-minimal --data-dir=/opt/var/weave --register user:password\'
echo and edit host\\port at \'/opt/etc/init.d/S92weave-minimal\'
endef

$(eval $(call BuildPackage,weave-minimal))
