# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2026 Entware

# The newer versions (5.0+)  requires Rust

include $(TOPDIR)/rules.mk

PKG_NAME:=suricata
PKG_VERSION:=4.1.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.openinfosecfoundation.org/download
PKG_HASH:=4013cb13a2f3f7854328cf072319bba41896fad86d6b85b1cff4004f82aa7276

PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYING LICENSE
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/suricata
	SECTION:=net
	CATEGORY:=Network
	TITLE:=IDS, IPS, NSM engine
	URL:=https://suricata-ids.org/
	DEPENDS:=+jansson +libcap-ng +liblz4 +libmagic +libpcap +libpcre +libyaml
endef

define Package/suricata/description
 The Suricata engine is capable of real time intrusion detection
 (IDS), inline intrusion prevention (IPS), network security monitoring (NSM)
 and offline pcap processing. Suricata inspects the network traffic using a
 powerful and extensive rules and signature language, and has powerful Lua
 scripting support for detection of complex threats.
endef

CONFIGURE_ARGS += \
	--disable-afl \
	--disable-nspr \
	--disable-nss \
	--disable-python \
	--disable-rust \
	--disable-static \
	--disable-suricata-update

define Package/suricata/conffiles
/opt/etc/suricata/suricata.yaml
/opt/etc/suricata/classification.config
/opt/etc/suricata/reference.config
/opt/etc/suricata/threshold.config
endef

define Package/suricata/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/suricata $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libhtp*.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/etc/suricata/rules
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/{classification,reference,threshold}.config \
		$(PKG_BUILD_DIR)/suricata.yaml \
		$(1)/opt/etc/suricata
	$(INSTALL_DIR) $(1)/opt/var/log/suricata/{certs,files}
endef

define Package/suricata/postinst
#!/bin/sh

echo 'Current Suricata ruleset can be found at'
echo 'https://rules.emergingthreats.net/open/old/suricata-4.0/emerging.rules.tar.gz'
endef

$(eval $(call BuildPackage,suricata))
