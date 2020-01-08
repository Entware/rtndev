#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by weave-minimal only, no need to update it
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-gevent
PKG_VERSION:=1.4.0
PKG_RELEASE:=1

PYPI_NAME:=gevent
PKG_HASH:=1eb7fa3b9bd9174dfe9c3b59b7a09b768ecd496debfc4976a9530a3e15c990d1

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python-gevent/Default
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=Python networking library
	URL:=http://www.gevent.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-gevent
$(call Package/python-gevent/Default)
  DEPENDS:=+PACKAGE_python-gevent:python-greenlet
  VARIANT:=python
endef

define Package/python3-gevent
$(call Package/python-gevent/Default)
  DEPENDS:=+PACKAGE_python3-gevent:python3-greenlet
  VARIANT:=python3
endef

define Package/python-gevent/description
 Gevent is a coroutine-based Python networking library that uses greenlet
 to provide a high-level synchronous API on top of the libevent event loop.
endef

define Package/python3-gevent/description
$(call Package/python-gevent/description)
.
(Variant for Python3).
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

define PyBuild/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Py3Build/Compile
	$(call Build/Compile/Py3Mod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-gevent/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
endef

define Package/python3-gevent/install
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON3_PKG_DIR)/* \
		$(1)$(PYTHON3_PKG_DIR)
endef

$(eval $(call PyPackage,python-gevent))
$(eval $(call BuildPackage,python-gevent))

$(eval $(call Py3Package,python3-gevent))
$(eval $(call BuildPackage,python3-gevent))
