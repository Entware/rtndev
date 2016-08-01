#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-gevent
PKG_VERSION:=1.1.1
PKG_RELEASE:=1

PKG_SOURCE:=gevent-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/12/dc/0b2e57823225de86f6e111a65d212c9e3b64847dddaa19691a6cb94b0b2e/
PKG_MD5SUM:=1532f5396ab4d07a231f1935483be7c3
PKG_BUILD_DEPENDS:=python
PKG_BUILD_DIR:=$(BUILD_DIR)/gevent-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-gevent
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python-greenlet
	TITLE:=Python networking library
	URL:=http://www.gevent.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/python-gevent/description
 Gevent is a coroutine-based Python networking library that uses greenlet
 to provide a high-level synchronous API on top of the libevent event loop.
endef

define Build/Configure
	touch $(PKG_BUILD_DIR)/c-ares/{Makefile.in,libcares.pc.in}
	(cd $(PKG_BUILD_DIR)/libev; \
	$(CONFIGURE_VARS) \
	./configure \
		--target=$(GNU_TARGET_NAME) \
		--host=$(GNU_TARGET_NAME) \
		--build=$(GNU_HOST_NAME) \
		--prefix=/opt \
	);
	(cd $(PKG_BUILD_DIR)/c-ares; \
	$(CONFIGURE_VARS) \
	./configure \
		--target=$(GNU_TARGET_NAME) \
		--host=$(GNU_TARGET_NAME) \
		--build=$(GNU_HOST_NAME) \
		--prefix=/opt \
	);
	$(call Build/Configure/Default)
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-gevent/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-gevent))
