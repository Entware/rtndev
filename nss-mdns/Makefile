# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2022 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=nss-mdns
PKG_VERSION:=0.15.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/lathiat/nss-mdns/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=2d1b8de2e9ed5526f51c8bb627b719c07668465b5315787e7cfeed776ab90b9a

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=LGPL-2.1-or-later
PKG_LICENSE_FILES:=LICENSE

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libnss-mdns
  SECTION:=libs
  CATEGORY:=Libraries
  SUBMENU:=Networking
  TITLE:=a plugin for the GNU Name Service Switch
  URL:=https://github.com/lathiat/nss-mdns
endef

define Package/libnss-mdns/description
  nss-mdns is a plugin for the GNU Name Service Switch (NSS) functionality
  of the GNU C Library (glibc) providing host name resolution via Multicast
  DNS (aka Zeroconf, aka Apple Rendezvous, aka Apple Bonjour), effectively
  allowing name resolution by common Unix/Linux programs in the ad-hoc mDNS
  domain .local.
endef

define Package/libnss-mdns/conffiles
/opt/etc/mdns.allow
endef

TARGET_LDFLAGS += $(if $(CONFIG_USE_GLIBC),-lresolv)

CONFIGURE_ARGS += \
	--disable-tests \
	AVAHI_SOCKET="/opt/var/run/avahi-daemon/socket" \
	MDNS_ALLOW_FILE="/opt/etc/mdns.allow"

define Package/libnss-mdns/install
	$(INSTALL_DIR) $(1)/opt/etc
	echo "*" > $(1)/opt/etc/mdns.allow
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libnss_mdns*.so.* $(1)/opt/lib
endef

define Package/libnss-mdns/postinst
#!/bin/sh

if ! grep -q '^hosts.*mdns' /opt/etc/nsswitch.conf; then
  sed -i 's,^hosts.*,hosts:      files mdns4_minimal [NOTFOUND=return] dns,' \
  /opt/etc/nsswitch.conf
fi
endef

define Package/libnss-mdns/postrm
#!/bin/sh

if grep -q '^hosts.*mdns' /opt/etc/nsswitch.conf; then
  sed -i 's,^hosts.*,hosts:      files dns,' /opt/etc/nsswitch.conf
fi
endef

$(eval $(call BuildPackage,libnss-mdns))
