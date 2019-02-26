#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# The newer version raises following error.
# Used by weave-minimal only, no need to update it
#
#In file included from deps/libuv/src/threadpool.c:22:0:
#deps/libuv/src/threadpool.c: In function 'uv__queue_done':
#deps/libuv/src/uv-common.h:196:24: error: request for member 'count' in something not a structure or union

include $(TOPDIR)/rules.mk

PKG_NAME:=python-gevent
PKG_VERSION:=1.2.2
PKG_RELEASE:=1

PKG_SOURCE:=gevent-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/1b/92/b111f76e54d2be11375b47b213b56687214f258fd9dae703546d30b837be
PKG_HASH:=4791c8ae9c57d6f153354736e1ccab1e2baf6c8d9ae5a77a9ac90f41e2966b2d
PKG_BUILD_DEPENDS:=python
PKG_BUILD_DIR:=$(BUILD_DIR)/gevent-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-gevent
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python-greenlet +USE_UCLIBC:librt
	TITLE:=Python networking library
	URL:=http://www.gevent.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-gevent/description
 Gevent is a coroutine-based Python networking library that uses greenlet
 to provide a high-level synchronous API on top of the libevent event loop.
endef

define Build/Configure
	touch $(PKG_BUILD_DIR)/deps/c-ares/{Makefile.in,libcares.pc.in}
	(cd $(PKG_BUILD_DIR)/deps/libev; \
	$(CONFIGURE_VARS) \
	./configure \
		--target=$(GNU_TARGET_NAME) \
		--host=$(GNU_TARGET_NAME) \
		--build=$(GNU_HOST_NAME) \
		--prefix=/opt \
	);
	(cd $(PKG_BUILD_DIR)/deps/c-ares; \
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
